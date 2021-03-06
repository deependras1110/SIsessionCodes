#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class product{
    public:

    string name;
    double quantity;
    double price;
};

class store{

    string name;
    vector <product> list;

    public:
        store(string name,string filename){

            this->name=name;
            
            //step1-check if you have fstream included or not, creating file object
            ifstream inFile;
            
            //step2-opening the file
            inFile.open(filename);

            //step3-checking the file opening 
            if(!inFile.is_open()){
                cout<<"error:file not working"<<endl;
                exit(0);
            }
            //step4- reading the file until the end of file is reached 
            while(!inFile.eof()){

                //step 5- settup string variable to read the line from file and the variables for stringstream
                string line_from_file;
                string intermediate;
                //string productName;
                //string productQunatity;
                //string productPrice;
                product p;

               

                ///step 6-reading the line from file
                getline(inFile,line_from_file);
                 //pasta,100,10=line_from_file
                
                //step 7-setting up the string stream
                stringstream ss(line_from_file);
                //ss= pasta,100,10

                //step 8-deliminator(always check the file structure for this)

                getline(ss,intermediate,',');
                //intermediate="pasta";
                p.name=intermediate;
                getline(ss,intermediate,',');
                //intermediate="100";
                p.quantity=stod(intermediate); //string to double
                getline(ss,intermediate,'\0');
                //intermediate="10";
                p.price=stod(intermediate); //string to double
                

                //step9- store info in vector,maps,arrays
                list.push_back(p);

            }
            //step10- closing the file
            inFile.close();
        }
        product check_and_return(string UserInput){
            int i;
            product p;
            for(i=0;i<list.size();i++){
                if(list.at(i).name.compare(UserInput)==0){
                        p=list.at(i);
                        break;
                        
                }
                else{
                    cout<<"not found!sorry"<<endl;
                }
                
            }
            return p;
        }
        void creating_receipt(string output_filename,vector <product> purchaseHistory){

            ofstream outf(output_filename);

            // // //if(!outf){
            //             cout<<"message"<<emdl;
            // // }
             int i;
             int total=0;
            if(!ofstream.is_open()){
                cout<<"unsucessful attempt at opening this file"<<endl;
            }
            outf<<name<<endl;
            outf<<"ADDRESS HERE"<<endl;

            for(i=0;i<purchaseHistory.size();i++){
                outf<<purchaseHistory.at(i).name<<" "<<purchaseHistory.at(i).quantity<<" "<<purchaseHistory.at(i).price<<endl;
                total+=purchaseHistory.at(i).price;
            }
            outf<<"Your Total is:"<<total<<endl;
            outf<<"Thank you for shopping with us"<<endl;


        }
    

};

int main(int argc, char**argv){


    store w(argv[1],argv[2]);
    string answer;
    product product_from_invetory;
    vector <product> purchase_history;

    while(answer!="exit"){
        
        cout<<"Hey! what do you want?"<<endl;
        cin>>answer;
        product_from_invetory=w.check_and_return(answer);
        purchase_history.push_back(product_from_invetory);

    }
    cout<<"Thank you! do you want receipt?"<<endl
    cin>>answer;
    if(answer.compare("yes")==0){
        w.creating_receipt("/home/devuser/Documents/sipractice/receipt.txt",purchase_history);
    }

}