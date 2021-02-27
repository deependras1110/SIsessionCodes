#include<iostream>
#include <vector>

using namespace std;

class Book{
public:
    string name;
    float price;

    Book(string name,float price){
        this->name=name;
        this->price=price;
    }

    Book(float price){
        this->name="unknown";
        this->price=price;
    }

};

int main (){
    int i;
    Book* b_ptr;
    string answer; //all sort of input
    vector <Book> list;

    while(answer!="exit"){
        cout<<"Adding book..."<<endl;
        cout<<"Do you know the book name?"<<endl;
        cin>>answer;

        if(answer=="yes"){
            cout<<"enter the book name?"<<endl;
            cin>>answer;
            b_ptr=new Book(answer,2.99); 
            list.push_back(*b_ptr);

        }
        else if(answer=="no"){
            b_ptr=new Book(2.99);
            list.push_back(*b_ptr);
        }
        else{
          cout<<"invalid input"<<endl;
        }
        
        cout<<"All books so far"<<endl;
        for(i=0;i<list.size();i++){
            cout<<list.at(i).name<<" price:"<<list.at(id_t).price<<endl;
        }



    }


}