#include "MapFunWorking.h"
#include "main.h"
MapFunWorking::MapFunWorking(unique_ptr<NetworkDispatcher>* network)
{
	this->networkConnect = network;
}

void MapFunWorking::run()
{

	while (!this->networkConnect->get()->connection_Status)
	{
		try
		{
			this->networkConnect->get()->connectServer();
		}
		catch (const runtime_error& e)
		{
			cerr << e.what() << endl;
		}
	}
	cout << "[*]���ӳɹ�!" << endl;
	
	//this->networkConnect->get()->sendData();

}

MapFunWorking::~MapFunWorking()
{

}
