#include <json/json.h>
#include <iostream>
#include <string>
#include "Network.h"
#include "../GameState/Player.h"
#define CURL_STATICLIB
#include <curl/curl.h>
#define statusCode unsigned short

// #pragma comment(lib,"libcurl_a.lib")

/*

���������� ��� ��� �������, ���� ��� ������ � ��, ������ ��� ������ �� ��:
send_user_to_db(Player& plr) � get_user_from_db(std::string&& name, Json::Value& body) 
��������������.
� ������ ��������� ������ ������ �� ������, ������������ ���,
���� �� ����� 0 - �� �������,
����� - ��������� �����-�� ������.
�� ������ ��������� ��� ������(id) � ������ ���� Json::Value, ������� �������� �������,
���� ��� 0 - �������,
���� ��� 1 - �� ������ ������ ���,
����� - ������.
������ ���� Json::Value ����� ��� �������� � ����� GameState.addPlayer(Json::Value& obj, sock)
���� ����� ��� ������� ���������� ������ addPlayer(...).

*/



static size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

static WSASession Session;
static UDPSocket Socket;
static const unsigned short buf_size = 1024;


inline void send_user_to_db(unsigned short& status_code, Player& plr) {
	Json::Value root;

	plr.get_info(root);

	CURL* curl;
	curl = curl_easy_init();

	std::string readBuffer;
	std::string url = "http://localhost:8000/user/";

	struct curl_slist* chunk = NULL;
	CURLcode res;
	
	
	if (curl) {
		Json::FastWriter fastWriter;
		std::string output = fastWriter.write(root);
		chunk = curl_slist_append(chunk, "Accept: application/json");
		chunk = curl_slist_append(chunk, "Accept-Encoding: gzip, deflate, br");
		chunk = curl_slist_append(chunk, "charset: utf-8");
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, output.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
				/*std::cout << "res" << readBuffer;*/
		curl_easy_cleanup(curl);

	}

}

inline void get_user_from_db(unsigned short& status_code, std::string&& name, Json::Value& body){
	CURL* curl;

	curl = curl_easy_init();

	std::string readBuffer;
	std::string url = "http://localhost:8000/user/" + name;
	CURLcode res;

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		res = curl_easy_perform(curl);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &status_code);

		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));
		/*std::cout << "res" << readBuffer;*/
		curl_easy_cleanup(curl);

		Json::Reader reader;
		reader.parse(readBuffer, body);
	}
}


//int main11111() {
//	/*Json::Value root;
//	Json::Reader reader;
//	std::string str;
//	getline(std::cin, str);
//	std::cout << str;
//	reader.parse(str.c_str(), root);
//
//	std::cout << root << "\n";*/
//
//	/*Player plr("ad", 12, 34);
//	send_user_to_db(plr);
//	Json::Value b;
//	get_user_from_db("ad", b);
//	std::cout << b;*/
//	//Player p;
//
//	/*CURL* curl;
//	CURLcode res;
//
//	curl = curl_easy_init();
//
//	std::string readBuffer;
//	if (curl) {
//		curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8000/user/332");
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
//		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
//
//		res = curl_easy_perform(curl);
//		if (res != CURLE_OK)
//			fprintf(stderr, "curl_easy_perform() failed: %s\n",
//				curl_easy_strerror(res));
//		std::cout << "res" << readBuffer;
//		curl_easy_cleanup(curl);
//	}
//	return 0;*/
//	statusCode code_;
//	Json::Value ans;
//	get_user_from_db(code_, "dsfasdfsda", ans);
//	std::cout << ans << ' ' << code_;
//	/*while (true) {
//		unsigned short res;
//		Json::Value b;
//		get_user_from_db(res, "dd", b);
//		std::cout << res << '\n';
//		std::cout << b << '\n';
//		Player plr("14", 125, 34);
//		send_user_to_db(res, plr);
//		std::cout << res;
//		if (res != 200) {
//			break;
//		}
//	}*/
//}
