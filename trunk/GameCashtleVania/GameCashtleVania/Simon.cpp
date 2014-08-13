#include "Simon.h"
#include "utils.h"
#include "Input.h"
#include "TagClassName.h"
#include "IronRodFac.h"
#include "ManageSprite.h"
#include "HideObject.h"
#include "ManageGame.h"

Simon* Simon::_instance = NULL;

Simon* Simon::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new Simon();
	}

	return _instance;
}

Simon* Simon::createInstance(std::vector<std::string> arr)
{
	if (_instance == NULL)
	{
		_instance = new Simon(arr);
	}

	return _instance;
}

Simon::Simon() : DynamicObject()
{

}

Simon::Simon(std::vector<std::string> arr)
{
	this->_ID = atoi(arr.at(0).c_str());
	this->_ID_Image = atoi(arr.at(1).c_str());
	this->_width = atoi(arr.at(3).c_str());
	this->HeightDefault = atoi(arr.at(4).c_str());
	this->HeightSit = 50;
	this->_height = HeightDefault;
	this->_isAnimatedSprite = true;

	//doc tu map
	this->_pos.x = 60;
	this->_pos.y = 66;
	this->z = 1;

	//IMove
	this->_Vx_default = atoi(arr.at(5).c_str());
	this->_Vy_default = atoi(arr.at(6).c_str());
	this->_JumH_Max = atoi(arr.at(7).c_str());

	//IAnimated
	this->_curFrame = 0;
	this->_coloumn = atoi(arr.at(8).c_str());
	this->_totalFrames = atoi(arr.at(9).c_str());
	this->_elapseTimeSwitchFrame = EslapseTimeSwitchFrame;
	this->_beforeTimeOld = 0.0f;

	this->_rectRS = this->updateRectRS(this->_width, this->_height);

	_moveMent = SimonMove::Free;
	this->_CanJum = true;
	this->_CanMoveL = true;
	this->_CanMoveR = true;
	//this->_vx = this->_Vx_default;
	//this->_vy = this->_Vy_default;

	this->_Left = false;

	//nhay toi vi tri cao nhat thi dung lai 0.2. sau do moi roi
	this->_CanJum = true;
	this->delayJump = 0.15;//doc tu file luon.
	this->_timeDelayJumpCur = 0.0f;

	//khoi tao Rod khi tao Simon
	ironRod = IronRodFac::getInstance()->createObj();
	//ironRod = new IronRod();
	this->_attacking = false;

	//Onstair
	this->_onStair = false;
	this->_prepareDownStairLeft = false;
	this->_prepareDownStairRight = false;
	this->_prepareUpStairLeft = false;
	this->_prepareUpStairRight = false;
	this->_stepOnStair = StepOnStair::Step0;
	this->_elapseTimeMoveStair = this->_elapseTimeSwitchFrame * 1.4;
	this->_timeDelayMoveStair = 0.0f;
}

// UPdate trang thai cua simon truoc. Sau do moi tinh cho no Move nhu the nao
void Simon::updateMovement(float delta_Time)
{
	//reset flag
	this->_onStair = false;
	
	switch (_moveMent)
	{
	case None:
		break;
	case Moves:
		if (_attacking)
		{
			this->_moveMent = SimonMove::Idle;
			this->_vx = 0;
			this->_vy = 0;
		}else
		{
			this->_CanJum = true;
			this->_CanMoveL = true;
			this->_CanMoveR = true;
			this->_High_Jumped = 0;
			this->_vy = 0;

			if (this->_Left)//dang di chuyen qua ben trai
			{
				this->_vx = -this->_Vx_default;
			}else
			{
				this->_vx = this->_Vx_default;
			}
		}
		break;
	case Idle:
		this->_CanMoveL = true;
		this->_CanMoveR = true;
		this->_High_Jumped = 0;
		this->_CanJum = true;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case Sit:
		this->_CanMoveL = false;
		this->_CanMoveR = false;
		this->_High_Jumped = 0;
		this->_CanJum = false;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case UpStair:
		this->_onStair = true;
		this->_CanMoveL = false;
		this->_CanMoveR = false;
		this->_High_Jumped = 0;
		this->_CanJum = false;
		this->_vx = 0.0f;
		this->_vy = 0.0f;

		//chuyen frame va dich chuyen simon len cau thang
		this->_timeDelayMoveStair += delta_Time;
		if (_timeDelayMoveStair >= _elapseTimeMoveStair)
		{
			_timeDelayMoveStair = 0.0f;
			this->_stepOnStair = (StepOnStair)((int)this->_stepOnStair + 1);
			if (this->_stepOnStair == StepOnStair::Step2)
			{
				this->_moveMent = SimonMove::OnStairUp;
			}

			//dich chuyen vi tri
			this->_pos.y += (this->_rectOfStair.top - this->_rectOfStair.bottom) / 4;
			float dir = this->_Left ? -1 : 1;
			this->_pos.x += dir * (this->_rectOfStair.right - this->_rectOfStair.left) / 4;
		}
		break;
	case DownStair:
		this->_onStair = true;
		this->_CanMoveL = false;
		this->_CanMoveR = false;
		this->_High_Jumped = 0;
		this->_CanJum = false;
		this->_vx = 0.0f;
		this->_vy = 0.0f;

		//chuyen frame va dich chuyen simon len cau thang
		this->_timeDelayMoveStair += delta_Time;
		if (_timeDelayMoveStair >= _elapseTimeMoveStair)
		{
			_timeDelayMoveStair = 0.0f;
			this->_stepOnStair = (StepOnStair)((int)this->_stepOnStair + 1);
			if (this->_stepOnStair == StepOnStair::Step2)
			{
				this->_moveMent = SimonMove::OnStairDown;
			}

			//dich chuyen vi tri
			this->_pos.y += (this->_rectOfStair.bottom - this->_rectOfStair.top) / 4;
			float dir = this->_Left ? -1 : 1;
			this->_pos.x += dir * (this->_rectOfStair.right - this->_rectOfStair.left) / 4;
		}
		break;
	case OnStairUp:
		//khong chuyen frame
		this->_onStair = true;
		this->_CanMoveL = false;
		this->_CanMoveR = false;
		this->_High_Jumped = 0;
		this->_CanJum = false;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case OnStairDown:
		//khong chuyen frame
		this->_onStair = true;
		this->_CanMoveL = false;
		this->_CanMoveR = false;
		this->_High_Jumped = 0;
		this->_CanJum = false;
		this->_vx = 0.0f;
		this->_vy = 0.0f;
		break;
	case Jump:
		this->_vy = this->_Vy_default;
		this->_High_Jumped += this->_vy * delta_Time;
		this->_CanJum = false;

		//khi dang nhay thi khong the di chuyen. Chi dua vao van toc dau. Van toc dau > 0 thi co Jump and Move
		this->_CanMoveL = false;
		this->_CanMoveR = false;

		if (this->_vx != 0)
		{
			//co nen giam toc do cua vx ko?
			this->_pos.x += delta_Time * this->_vx;
		}

		//da dat toi nguong --> delay. rot xuong
		if (this->_High_Jumped >= this->_JumH_Max)
		{
			this->_vy = 0.0f;
			this->_timeDelayJumpCur += delta_Time;

			if (this->_timeDelayJumpCur >= delayJump)
			{
				//het thoi gian delay. Roi xuong thoi!!!
				this->_timeDelayJumpCur = 0.0f;
				this->_moveMent = SimonMove::Free;
			}
		}
		break;
	case Free:
		this->_vy = -this->_Vy_default * 2;
		this->_High_Jumped = 0;
		this->_CanJum = false;

		//khi dang nhay thi khong the di chuyen. Chi dua vao van toc dau. Van toc dau > 0 thi co Jump and Move
		this->_CanMoveL = false;
		this->_CanMoveR = false;

		if (this->_vx != 0)
		{
			//co nen giam toc do cua vx ko?
			this->_pos.x += delta_Time * this->_vx * 2;
		}

		break;
	default:
		break;
	}

	//chuyen cac bien prepare stair -> false
	//khi co va cham thi thay doi lai bien do.
	//sau do processInput
	this->_prepareDownStairLeft = false;
	this->_prepareDownStairRight = false;
	this->_prepareUpStairLeft = false;
	this->_prepareUpStairRight = false;
}

void Simon::move(float delta_Time)
{
	if ((this->_CanMoveL && this->_vx < 0) || (this->_CanMoveR && this->_vx > 0))
	{
		//co the di qua ben trai va v
		this->_pos.x += this->_vx * delta_Time;
		this->_moveMent = SimonMove::Idle;
	}
	
	this->_pos.y += this->_vy * delta_Time;
}

void Simon::update(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chuyen cac bien prepare stair -> false
	//khi co va cham thi thay doi lai bien do.
	//sau do processInput
	updateMovement(deltatime);

	handleCollision(deltatime, _listObjectCollision);

	
	move(deltatime);

	processInput();

	animated(deltatime);
	//updateMovement(deltatime);

	//updateMovement(deltatime);

	this->_box = this->getBox();
	
	ironRod->update(deltatime, _listObjectCollision);

	if (!ironRod->_isALive)
	{
		this->_attacking = false;
	}else
	{
		int dir = ironRod->_Left ? 1 : -1;
		ironRod->_pos.x = this->_pos.x - dir * 28; 
		ironRod->_pos.y = this->_pos.y;
	}
}

void Simon::animated(float deltatime)
{
#pragma region Dang su dung vu khi

	//Dang su dung roi
	if (_attacking)
	{
		switch (_moveMent)
		{
		case None:
			break;
		case Moves:
			this->_curFrame = 4 + ironRod->getStateRod();
			break;
		case Idle:
			this->_curFrame = 4 + ironRod->getStateRod();
			break;
		case Sit:
			this->_curFrame = 14 + ironRod->getStateRod();
			break;
		case OnStairUp:
			this->_curFrame = 20 + ironRod->getStateRod();
			break;
		case OnStairDown:
			this->_curFrame = 17 + ironRod->getStateRod();
			break;
		case Jump:
			this->_curFrame = 4 + ironRod->getStateRod();
			break;
		case Free:
			this->_curFrame = 4 + ironRod->getStateRod();
			break;
		default:
			break;
		}
		this->_rectRS = this->updateRectRS(this->_width, this->_height);
		return;
	}

#pragma endregion

#pragma region Khong su dung vu khi

	this->_beforeTimeOld += deltatime;
	if (_beforeTimeOld > _elapseTimeSwitchFrame)
	{
		_beforeTimeOld -= _elapseTimeSwitchFrame;
		switch (_moveMent)
		{
		case None:
			break;
		case Moves:
			this->_curFrame ++;
			if (_curFrame > 3 )
			{
				_curFrame = 0;
			}
			break;
		case Idle:
			this->_curFrame = 0;
			break;
		case Sit:
			this->_curFrame = 4;
			break;
		case UpStair:
			switch (this->_stepOnStair)
			{
			case StepOnStair::Step0:
				this->_curFrame = 12;
				break;
			case StepOnStair::Step1:
				this->_curFrame = 13;
				break;
			case StepOnStair::Step2:
				this->_curFrame = 12;
				break;
			default:
				break;
			}
			break;
		case DownStair:
			switch (this->_stepOnStair)
			{
			case StepOnStair::Step0:
				this->_curFrame = 10;
				break;
			case StepOnStair::Step1:
				this->_curFrame = 11;
				break;
			case StepOnStair::Step2:
				this->_curFrame = 10;
				break;
			default:
				break;
			}
			break;
		case OnStairUp:
			this->_curFrame = 12;
			break;
		case OnStairDown:
			this->_curFrame = 10;
			break;
		case Jump:
			this->_curFrame = 4;
			break;
		case Free:
			this->_curFrame = 0;
			break;
		default:
			break;
		}
	}
	this->_rectRS = this->updateRectRS(this->_width, this->_height);

#pragma endregion
}

RECT* Simon::updateRectRS(int width, int height)
{
	RECT* rectRS = new RECT();
	int x,y;
	x = (_curFrame % _coloumn) * width;
	y = (_curFrame / _coloumn) * HeightDefault;
	//cập nhật lại vị trí của Rect Resource
	rectRS->left = x;
	rectRS->right = x + width;
	rectRS->top = y ;
	rectRS->bottom = y + height;

	return rectRS;
}

void Simon::processInput()
{
	Input::CreateInstance()->ProcessKeyboard();

	Input::CreateInstance()->Update();

	int key = Input::CreateInstance()->GetKeyDown();
	int key_up = Input::CreateInstance()->GetKeyUp();

#pragma region Xu ly phim Left - Right
	//de phim
	if (Input::CreateInstance()->IsKeyDown(DIK_RIGHT) && this->_CanMoveR && !this->_attacking)
	{
		if (this->_moveMent == SimonMove::Moves || this->_moveMent == SimonMove::Idle)
		{
			this->_moveMent = SimonMove::Moves;
			this->_Left = false;
		}
	}else
	{
		if (Input::CreateInstance()->IsKeyDown(DIK_LEFT) && this->_CanMoveL && !this->_attacking)
		{
			if (this->_moveMent == SimonMove::Moves || this->_moveMent == SimonMove::Idle)
			{
				this->_moveMent = SimonMove::Moves;
				this->_Left = true;
			}
		}
	}
#pragma endregion

#pragma region XU ly phim down

	//Neu phim Down khong duoc nhan. thi chuyen ve stand neu no dang ngoi
	if (key_up == DIK_DOWN && !this->_attacking)
	{
		if (this->_moveMent == SimonMove::Sit)
		{
			this->_moveMent = SimonMove::Idle;
			//thay doi chieu cao, dong thoi fix vi tri
			this->_height = this->HeightDefault;
			this->_pos.y += (this->HeightDefault - this->HeightSit) / 2;
		}
	}else
	{
#pragma region Nhan Phim Down

		//neu de phim Down thi chuyen sang ngoi neu simon dang dung yen
		if (Input::CreateInstance()->IsKeyDown(DIK_DOWN) || key == DIK_DOWN)
		{
			//if (this->_moveMent == SimonMove::Idle)
			{
				//dang o trang thai chuan bi di xuong
				//if (this->_moveMent == SimonMove::PrepareDownTheStairLeft)
				if (this->_prepareDownStairLeft && !this->_onStair)
				{
					//chuyen sang trang thai xuong cau thang va quay mat ve ben trai
					this->_moveMent = SimonMove::DownStair;
					this->_pos.x = _rectOfStair.left + this->_width / 4;
					this->_pos.y = _rectOfStair.bottom + this->_height / 2;
					this->_stepOnStair = StepOnStair::Step0;
					this->_Left = true;
				}else
				{
					//if (this->_moveMent == SimonMove::PrepareDownTheStairRight)
					if (this->_prepareDownStairRight && !this->_onStair)
					{
						this->_moveMent = SimonMove::DownStair;
						this->_Left = false;
						this->_pos.x = _rectOfStair.left  - this->_width / 4;
						this->_pos.y = _rectOfStair.bottom + this->_height / 2;
						this->_stepOnStair = StepOnStair::Step0;
					}else
					{
						if (this->_moveMent == SimonMove::OnStairUp || this->_moveMent == SimonMove::OnStairDown)
						{
							if (this->_moveMent == SimonMove::OnStairUp)
							{
								this->_Left = !this->_Left;
							}

							this->_moveMent = SimonMove::DownStair;
							this->_stepOnStair = StepOnStair::Step0;
						}
					}
				}
			}

			//chua chuyen trang thai movement thi chuyen sang ngoi. Truong hop khac cua cac truong hop tren
			if (this->_moveMent == SimonMove::Idle && !this->_prepareDownStairLeft && !this->_prepareDownStairRight)
			{
				this->_moveMent = SimonMove::Sit;
				//giam chieu cao 1 nua, dong thoi fix lai vi tri
				this->_height = this->HeightSit;
				this->_pos.y -= (this->HeightDefault - this->HeightSit) / 2;
			}	
		}

#pragma endregion
	}

#pragma endregion
	
#pragma region Xu ly phim UP
	//neu de phim Up de di len cau thang
	if (Input::CreateInstance()->IsKeyDown(DIK_UP) || key == DIK_UP)
	{
		//dang o trang thai chuan bi di xuong
		//if (this->_moveMent == SimonMove::PrepareDownTheStairLeft)
		if (this->_prepareUpStairLeft && !this->_onStair)
		{
			//chuyen sang trang thai xuong cau thang va quay mat ve ben trai
			this->_moveMent = SimonMove::UpStair;
			this->_pos.x = _rectOfStair.left;
			this->_pos.y = _rectOfStair.bottom + this->_height / 2;
			this->_stepOnStair = StepOnStair::Step0;
			this->_Left = true;
		}else
		{
			//if (this->_moveMent == SimonMove::PrepareDownTheStairRight)
			if (this->_prepareUpStairRight && !this->_onStair)
			{
				this->_moveMent = SimonMove::UpStair;
				this->_Left = false;
				this->_pos.x = _rectOfStair.left;// + (_rectOfStair.right - _rectOfStair.left) / 2
				this->_pos.y = _rectOfStair.bottom + this->_height / 2;
				this->_stepOnStair = StepOnStair::Step0;
			}else
			{
				if (this->_moveMent == SimonMove::OnStairUp || this->_moveMent == SimonMove::OnStairDown)
				{
					if (this->_moveMent == SimonMove::OnStairDown)
					{
						this->_Left = !this->_Left;
					}

					this->_moveMent = SimonMove::UpStair;
					this->_stepOnStair = StepOnStair::Step0;
					
				}
			}
		}
	}
#pragma endregion

#pragma region Xu ly phim SPACE
	if (key == DIK_SPACE && !this->_attacking)
	{
		if (this->_CanJum)
		{
			this->_moveMent = SimonMove::Jump;
		}
	}
#pragma endregion

#pragma region Xu Ly Phim Z
	if (key == DIK_Z)
	{
		//chua su dung roi
		if (!this->_attacking && this->_moveMent != SimonMove::DownStair && this->_moveMent != SimonMove::UpStair)
		{
			this->_attacking = true;
			IronRod::getInstance()->Use(this->_pos, this->_Left);
		}
	}
#pragma endregion

}

void Simon::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//lay box collider khi bat dau xu ly va cham
	this->_box = this->getBox();
	float normalX = 0;
	float normalY = 0;
	float timeCollision;
	for (int i = 0; i < _listObjectCollision.size(); i++)
	{
		ObjectGame* obj = _listObjectCollision.at(i);
#pragma region Object Game la HideObject

		if (obj->className() == TagClassName::getInstance()->tagHideObject)
		{
			HideObject* hideObj = (HideObject*)obj;
			//va cham voi doi tuong nen
			timeCollision = this->collision((StaticObject*)obj, normalX, normalY, deltatime);
			//if ( !((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f))
			//{
			//	//khong co va cham
			//	break;
			//}
#pragma region HideObject = Ground
			if (hideObj->getTypeHideObject() == TypeHideObect::Ground)
			{
				if (timeCollision == 2.0f)
				{
					// bi va cham theo AABBCheck
					if (this->_moveMent == SimonMove::Free && normalY >= 0)
					{
						//dang roi
						if (this->getRect().bottom > hideObj->getRect().bottom)
						{
 							this->_moveMent = SimonMove::Idle;
							this->_pos.x += normalX;
							this->_pos.y += normalY;
							//this->_vx = 0;
							this->_vy = 0;
						}

					}

					if (this->_moveMent == SimonMove::Moves && normalX != 0)
					{
						this->_moveMent = SimonMove::Idle;
						this->_pos.x += normalX;
						this->_pos.y += normalY;
						this->_vx = 0;
					}
				}else
				{
					//truong hop duoi
				}
				if (timeCollision < 1.0f)//co va cham
				{
					//Object dang di chuyen qua ben trai
					if (normalX == 1)
					{
						

						if (this->_moveMent == SimonMove::Jump)
						{
							this->_moveMent == SimonMove::Free;
						}

						if (this->_moveMent == SimonMove::Moves)
						{
							this->_pos.x += timeCollision * (deltatime * this->_vx) + 0.5f;
							this->_moveMent = SimonMove::Idle;
							this->_vx = 0;
							this->_CanMoveL = false;
						}
						
					}

					//Object dang di chuyen qua ben phai
					if (normalX == -1)
					{
						
						if (this->_moveMent == SimonMove::Jump)
						{
							this->_moveMent == SimonMove::Free;
						}

						if (this->_moveMent == SimonMove::Moves)
						{
							this->_pos.x += timeCollision * (deltatime * this->_vx) - 0.5f;
							this->_moveMent = SimonMove::Idle;
							this->_vx = 0;
							this->_CanMoveR = false;
						}
					}

					//Obj dang roi
					if (normalY == 1)
					{
						if (this->_moveMent == SimonMove::Free)
						{
							this->_pos.y += timeCollision * (deltatime * this->_vy);
							this->_moveMent = SimonMove::Idle;
							//this->_vx = 0;
							this->_vy = 0;
						}
						
					}

					//obj dang nhay
					if (normalY == -1)
					{
						//ko lam gi ca
					}
				}
			}
#pragma endregion
			else
			{
#pragma region Hide Object = Stop Scrooll

				if (hideObj->getTypeHideObject() == TypeHideObect::StopScrollScene)
				{
					//va cham voi doi tuong stop scroll
					if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
					{
						ManageSprite::createInstance()->_camera->stopScrollScreen = true;											
					}

					//khi di qua lai ben trai va vuot left cua hide object -> cuon lai
					if (this->_pos.x + this->_width / 2 <= hideObj->_pos.x - hideObj->_width / 2)
					{
						ManageSprite::createInstance()->_camera->stopScrollScreen = false;	
					}
				}
#pragma endregion
				else
				{
#pragma region HideObject = ChangeScene

					if (hideObj->getTypeHideObject() == TypeHideObect::ChangeScene)
					{
						//change scene
						//va cham voi doi tuong change Scene
						if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
						{
							ManageGame::isChangeScene = true;					
						}
					}

#pragma endregion
					else
					{
#pragma region HideObject = UpstairLeft
						if (hideObj->getTypeHideObject() == TypeHideObect::UpStairLeft)
						{
							if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
							{
								this->_prepareUpStairLeft = true;
								//this->_moveMent = SimonMove::PrepareUpTheStairLeft;
								this->posPrepareOnStair = hideObj->_pos;
								this->_rectOfStair = hideObj->getRect();
								
								//dang dung tren cau thang
								if (this->_onStair)
								{
									//chenh lech khong qua 5 pixel
									if ( abs(this->getRect().bottom - _rectOfStair.bottom) < 5 )
									{
										this->_moveMent = SimonMove::Idle;
										this->_pos.y = _rectOfStair.bottom + this->_height / 2;
									}
								}
							}
						}
#pragma endregion
						else
						{
#pragma region HideObject = DownStairLeft
							if (hideObj->getTypeHideObject() == TypeHideObect::DownStairLeft)
							{
								if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
								{
									this->_prepareDownStairLeft = true;
									//this->_moveMent = SimonMove::PrepareDownTheStairLeft;
									this->posPrepareOnStair = hideObj->_pos;
									this->_rectOfStair = hideObj->getRect();	

									//dang dung tren cau thang
									if (this->_onStair)
									{
										//chenh lech khong qua 5 pixel
										if ( abs(this->getRect().bottom - _rectOfStair.bottom) < 5 )
										{
											this->_moveMent = SimonMove::Idle;
											this->_pos.y = _rectOfStair.bottom + this->_height / 2;
										}
									}
								}
							}
#pragma endregion
							else
							{
#pragma region HideObject = UpStairRight
								if (hideObj->getTypeHideObject() == TypeHideObect::UpStairRight)
								{
									if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
									{
										this->_prepareUpStairRight = true;
										//this->_moveMent = SimonMove::PrepareUpTheStairRight;
										this->posPrepareOnStair = hideObj->_pos;
										this->_rectOfStair = hideObj->getRect();

										//dang dung tren cau thang
										if (this->_onStair)
										{
											//chenh lech khong qua 5 pixel
											if ( abs(this->getRect().bottom - _rectOfStair.bottom) < 5 )
											{
												this->_moveMent = SimonMove::Idle;
												this->_pos.y = _rectOfStair.bottom + this->_height / 2;
											}
										}
									}
								}
#pragma endregion
								else
								{
#pragma region HideObject = DownStairRight
									if (hideObj->getTypeHideObject() == TypeHideObect::DownStairRight)
									{
										if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
										{
											this->_prepareDownStairRight = true;
											//this->_moveMent = SimonMove::PrepareDownTheStairRight;
											this->posPrepareOnStair = hideObj->_pos;
											this->_rectOfStair = hideObj->getRect();	

											//dang dung tren cau thang
											if (this->_onStair)
											{
												//chenh lech khong qua 5 pixel
												if ( abs(this->getRect().bottom - _rectOfStair.bottom) < 5 )
												{
													this->_moveMent = SimonMove::Idle;
													this->_pos.y = _rectOfStair.bottom + this->_height / 2;
												}
											}
										}
									}
#pragma endregion
									else
									{
#pragma region HideObject = Free
										if (hideObj->getTypeHideObject() == TypeHideObect::Free)
										{
											if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
											{
												if (this->_moveMent == SimonMove::Moves || this->_moveMent == SimonMove::Idle)
												{
													if (this->_Left)
													{
														//dang di qua ben trai
														if (this->getRect().right <= hideObj->getRect().right)
														{
															this->_moveMent = SimonMove::Free;
														}
													}
													else
													{
														//dang di qua ben phai
														if (this->getRect().left >= hideObj->getRect().left)
														{
															this->_moveMent = SimonMove::Free;
														}
													}
												}
												//this->_moveMent = SimonMove::Free;				
											}
										}
#pragma endregion
									}
								}
							}
						}
					}

				}
			}	
		}

#pragma endregion
	
#pragma region Object = Enemy
		
		if (obj->className() == TagClassName::getInstance()->tagEnemy)
		{
			timeCollision = this->collision((DynamicObject*)obj, normalX, normalY, deltatime);

			if ((timeCollision > 0.0f && timeCollision < 1.0f) || timeCollision == 2.0f)
			{
				//va cham voi enemy
				this->_moveMent = SimonMove::CollisionEnemy;
				this->_collisionEnemy = true;
			}
		}

#pragma endregion

		
	}
}

//implement method collision
float Simon::collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime)
{
	Box box = this->getBox();
	Box staticBox = ICollision::getInstance()->getSweptBroadphaseBox(dynamicOject->getBox(), deltaTime);

	Box broadphaseBox = ICollision::getInstance()->getSweptBroadphaseBox(box, deltaTime);

	float moveX = 0;
	float moveY = 0;

	//kiem tra 2 box hien tai da va cham chua
	if (ICollision::getInstance()->AABBCheck(box, staticBox))
	{
		if (ICollision::getInstance()->AABB(box, staticBox, moveX, moveY))
		{
			normalx = moveX;
			normaly = moveY;
			return 2.0f;
		}
		return 1.0f;
	}else
	{
		//kiem tra 2 object co the va cham ko?
		if (ICollision::getInstance()->AABBCheck(broadphaseBox, staticBox))
		{
			float timeCol = ICollision::getInstance()->sweptAABB(box, staticBox, normalx, normaly, deltaTime);
			return timeCol;
		}else
		{
			return 1.0;//khong co va cham
		}
	}

	return 0.0f;
}

float Simon::collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime)
{
	Box box = this->getBox();
	Box staticBox = staticObject->getBox();

	Box broadphaseBox = ICollision::getInstance()->getSweptBroadphaseBox(box, deltaTime);

	float moveX = 0;
	float moveY = 0;

	//kiem tra 2 box hien tai da va cham chua
	if (ICollision::getInstance()->AABBCheck(box, staticBox))
	{
		if (ICollision::getInstance()->AABB(box, staticBox, moveX, moveY))
		{
			normalx = moveX;
			normaly = moveY;
			//this->_pos.x += moveX;
			//this->_pos.y += moveY;
			return 2.0f;
		}
		return 1.0f;
	}else
	{
		//kiem tra 2 object co the va cham ko?
		if (ICollision::getInstance()->AABBCheck(broadphaseBox, staticBox))
		{
			float timeCol = ICollision::getInstance()->sweptAABB(box, staticBox, normalx, normaly, deltaTime);
			return timeCol;
		}else
		{
			return 1.0;//khong co va cham
		}
	}

	return 0.0f;
}