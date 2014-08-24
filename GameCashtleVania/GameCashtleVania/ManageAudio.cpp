#include "ManageAudio.h"
#include "ManageTexture.h"

ManageAudio* ManageAudio::_instance = NULL;

ManageAudio::ManageAudio(void)
{
	_Music_Background = true;
	_Sound = true;
}

ManageAudio* ManageAudio::getInstance()
{
	if (_instance == NULL)
		_instance = new ManageAudio();

	return _instance;
}

int ManageAudio::init_DirectSound(HWND hWnd)
{
	HRESULT result;

	//create Direct Manage Sound Object
	soundManage = new CSoundManager();

	//initializa DirectSound
	result = soundManage->Initialize(hWnd, DSSCL_PRIORITY);
	if (result != DS_OK)
		return 0;

	//set the primaty buffer format
	result = soundManage->SetPrimaryBufferFormat(2, 22050, 16);
	if (result != DS_OK)
		return 0;

	//return success
	return 1;
}

void ManageAudio::addSound(int key, bool loop, std::string fileName)
{
	CSound* sound = this->loadSound(loop, fileName);
	this->listAudio[key] = sound;
}

CSound* ManageAudio::loadSound(bool loop, std::string fileName)
{
	HRESULT result;

	CSound *wave;

	result = soundManage->Create(&wave, (char*)fileName.c_str());
	if (result != DS_OK)
		return NULL;
	
	wave->loop = loop;
	return wave;
}

void ManageAudio::playSound(TypeAudio _type)
{
	std::hash_map<int, CSound*>::iterator it = this->listAudio.find((int)_type);
	if (it != this->listAudio.end())
	{
		CSound* sound = it->second;
		
		if (sound->loop)
		{
			sound->Play();
			//sound->Play(0, DSSCL_PRIORITY);
		}else
		{
			sound->Play();
		}
	}
}

void ManageAudio::loopSound(CSound *sound)
{
	sound->Play(0, DSSCL_PRIORITY);
}

void ManageAudio::stopSound(TypeAudio _type)
{
	std::hash_map<int, CSound*>::iterator it = this->listAudio.find((int)_type);
	if (it != this->listAudio.end())
	{
		CSound* sound = it->second;

		sound->Stop();
	}
}

ManageAudio::~ManageAudio(void)
{
}
