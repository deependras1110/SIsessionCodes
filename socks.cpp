#include <iostream>
#include<vector>
#include<sstream>

using namespace std;

class socks{
public:
    vector <string> colors;
    bool hole;

    void show_color(){
        int i;
        if(hole==true){
            cout<<"cant show the color, sock has hole in it"<<endl;
        }
        else{
            for(i=0;i<colors.size();i++){
                cout<<colors[i]<<endl;
            }
        }
    }
    void add_color_socks(){
        string all_color;
        string single;

        cout<<"Enter all the colors in one line"<<endl; 
        getline(cin,all_color); //taking input as line

        stringstream ss(all_color); //setting up

        while(ss>>single){
            colors.push_back(single);
        }
        cout<<"this sock has "<<colors.size();

    }
    void hole_or_no_hole(){
        string response;
        cout<<"do these sock have hole?"<<endl;
        cin>>response;
        if(response.compare("yes")==0{
            hole=true;
        }
        else{
            hole=false;
        }
    
    }

};

class drawer{
    string name;
    int length;
    int width;
    int max_socks_allowed;

    public:
        drawer (string name23, int length, int width){
            name=name23; //this is same as this->name=name23
            this->length=length;
            this->width=width;

            int area=length*width;
            
            if(area<5){
                //max_socks_allowed=3;
                this->max_socks_allowed=3;
            }
            else{
                //max_socks_allowed=5;
                this->max_socks_allowed=5;
            }

            cout<<name<<"drawers created"<<"max number of socks allowed"<<max_socks_allowed<<endl;
        }

};

