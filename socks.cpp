#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class socks{
public:
    vector <string> colors;
    bool hole;
    void show_color(){
        if(hole==true){
            cout<<"cant show the color,sock has hole in it";
        }
        else{
            int i;
            for(i=0;i<colors.size();i++){
                cout<<colors[i]<<endl;
            }
        }
    }
    void add_color_socks() {
                string all_color;
                string single;
                string response;
                int temp=0;
                cout << "Enter all the color in one line" << endl;
                getline(cin,all_color);
                stringstream ss(all_color);
                while (ss>>single) {
                    colors.push_back(single);
                }
                temp=1;
            }

            void hole_or_no_hole(){
                string response;
                cout<<"do these socks have hole?"<<endl;
                cin>>response;
                if(response.compare("yes")==0){
                    hole=true;
                }
                else{
                    hole=false;
                }
            }

    };

class drawer{
    int length;
    int width;
    int max_socks;
    string owner_name;
    vector <socks> sock_list;
public:
    drawer(string owner_name,int length,int width){
        this->owner_name=owner_name;
        this->length=length;
        this->width=width;

        if(length*width<5){
            max_socks=3;
            cout<<owner_name<<"Maximum socks allowed:3"<<endl;
        }
        else{
            max_socks=5;
           cout<<owner_name<<"Maximum socks allowed:3"<<endl;

        }
    }
    void add_socks(int n) {
        if (max_socks != 0) {
            for (int i = 0; i < n; i++) {
                socks s;
                cout << "--Adding Sock " << i + 1 << endl;
                s.add_color_socks();
                s.hole_or_no_hole();
                sock_list.push_back(s);
                max_socks -= 1;
            }
        }
        else{
            cout<<"drawer is full cant take this sock"<<endl;
        }
    }
    socks get_socks(int n){
        return sock_list[n-1];
    }



};

int main() {

    drawer d1("Raheem",2,2);
    drawer d2("John",3,4);

    d1.add_socks(2);
    d2.add_socks(3);
    d1.get_socks(1).show_color();


}
