#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//int main()
//{
//	int i = 1;
//	double j = 2.2;
//	printf("%d\n", i);
//	printf("%lf\n", j);
//
//	cout << i << endl;
//	cout << j << endl;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	//�����ƶ�д:�ڴ�����ʲô���ӣ���д����ʲô����
	ServerInfo ReadBin()
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ServerInfo info;
		ifstream ifs(_configfile.c_str());
		ifs.read((char*)&info, sizeof(info));
		return info;
	}

	void WriteBin(const ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ��д
		ofstream ofs(_configfile.c_str());
		ofs.write((char*)&info, sizeof(info));
	}

	//�ı���д:Ҫ����ת������
	ServerInfo ReadText()
	{
		ServerInfo info;
		ifstream ifs(_configfile.c_str());
		//���ܰ����ո������ո��ֹͣ
		ifs >> info._ip;
		ifs >> info._port;
		return info;
	}

	void WriteText(const ServerInfo& info)
	{
		//����1
		//char buff[128];
		//ofstream ofs(_configfile.c_str());
		//ofs.write(info._ip,strlen(info._ip));
		//ofs.put('\n');
		//itoa(info._port, buff, 10);//10��ʾʮ����
		//ofs.write(buff, strlen(buff));
		//ofs.put('\n');

		//����2
		ofstream ofs(_configfile.c_str());//ofstream������operator<<
		ofs << info._ip << endl;
		ofs << info._port << endl;
	}
private:
	string _configfile;//�����ļ�
};

void BinTest()
{
	ConfigManager cm;//����һ�������ļ�

	ServerInfo winfo;//����������Ϣip��port
	strcpy(winfo._ip, "127.0.0.1");
	winfo._port = 80;

	cm.WriteBin(winfo);//�������ļ���д����

	ServerInfo rinfo = cm.ReadBin();//�������ļ��������
}

void TextTest()
{
	ConfigManager cm;//����һ�������ļ�

	ServerInfo winfo;//����������Ϣip��port
	strcpy(winfo._ip, "127.0.0.1");
	winfo._port = 80;

	cm.WriteText(winfo);//�������ļ���д����

	ServerInfo rinfo = cm.ReadText();//�������ļ��������
}
int main()
{
	//BinTest();
	TextTest();
	return 0;
}
