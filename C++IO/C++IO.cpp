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
	int _port; // 端口
};

struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")
		:_configfile(configfile)
	{}

	//二进制读写:内存中是什么样子，读写就是什么样子
	ServerInfo ReadBin()
	{
		// 这里注意使用二进制方式打开读
		ServerInfo info;
		ifstream ifs(_configfile.c_str());
		ifs.read((char*)&info, sizeof(info));
		return info;
	}

	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写
		ofstream ofs(_configfile.c_str());
		ofs.write((char*)&info, sizeof(info));
	}

	//文本读写:要进行转换处理
	ServerInfo ReadText()
	{
		ServerInfo info;
		ifstream ifs(_configfile.c_str());
		//不能包含空格，遇到空格会停止
		ifs >> info._ip;
		ifs >> info._port;
		return info;
	}

	void WriteText(const ServerInfo& info)
	{
		//方法1
		//char buff[128];
		//ofstream ofs(_configfile.c_str());
		//ofs.write(info._ip,strlen(info._ip));
		//ofs.put('\n');
		//itoa(info._port, buff, 10);//10表示十进制
		//ofs.write(buff, strlen(buff));
		//ofs.put('\n');

		//方法2
		ofstream ofs(_configfile.c_str());//ofstream重载了operator<<
		ofs << info._ip << endl;
		ofs << info._port << endl;
	}
private:
	string _configfile;//配置文件
};

void BinTest()
{
	ConfigManager cm;//创建一个配置文件

	ServerInfo winfo;//设置配置信息ip和port
	strcpy(winfo._ip, "127.0.0.1");
	winfo._port = 80;

	cm.WriteBin(winfo);//往配置文件里写数据

	ServerInfo rinfo = cm.ReadBin();//从配置文件里读数据
}

void TextTest()
{
	ConfigManager cm;//创建一个配置文件

	ServerInfo winfo;//设置配置信息ip和port
	strcpy(winfo._ip, "127.0.0.1");
	winfo._port = 80;

	cm.WriteText(winfo);//往配置文件里写数据

	ServerInfo rinfo = cm.ReadText();//从配置文件里读数据
}
int main()
{
	//BinTest();
	TextTest();
	return 0;
}
