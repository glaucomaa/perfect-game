#include <json/json.h>
#include <iostream>
#include <string>
#include "Network.h"
#include "../GameState/Player.h"


static WSASession Session;
static UDPSocket Socket;
static const unsigned short buf_size = 1024;

char send_user_to_db(Player& plr) {
	Json::Value req;
	Json::Value root;
	char buffer[buf_size];

	plr.get_info(root);
	req["command"] = "00";
	req["body"] = root;

	Socket.SendTo("127.0.0.1", 9999, req.toStyledString().c_str(), req.toStyledString().size());
	Socket.RecvFrom(buffer, buf_size);
	
	Json::Reader reader;
	Json::Value ans;
	reader.parse(buffer, ans);

	return ans["code"].asInt();
}


char get_user_from_db(std::string&& name, Json::Value& body) {
	Json::Value req;
	char buffer[buf_size];

	req["command"] = "01";
	req["body"] = name;

	Socket.SendTo("127.0.0.1", 9999, req.toStyledString().c_str(), req.toStyledString().size());
	Socket.RecvFrom(buffer, buf_size);

	Json::Reader reader;
	Json::Value ans;
	reader.parse(buffer, ans);

	body = ans["body"];

	
	return ans["code"].asInt();
}



int main(){
	/*Json::Value root;  
	Json::Reader reader;
	std::string str;
	getline(std::cin, str);
	std::cout << str;
	reader.parse(str.c_str(), root);

	std::cout << root << "\n";*/

	/*Player plr("ad", 12, 34);
	send_user_to_db(plr);
	Json::Value b;
	get_user_from_db("ad", b);
	std::cout << b;*/
	//Player p;
}
