#include<iostream>

#include<cstdlib>

using namespace std;

class hash{

    private:

        int hash_pos;

        int array[40];

    public:

        hash();

        void insert(int);

        void search();
        
        void printHash();

        int Hash(int );

        int reHash(int );

};

void hash:: printHash(){
       
       for (int i = 0; i < 40; i++)
       {
       cout << array[i] << endl;
       }
       
}


hash::hash(){

    for(int i = 0; i < 40; i++){

        array[i] = '*';

    }

}

void hash::insert(int d){

    

    int count = 0;

    

    hash_pos = Hash(d);

    if(hash_pos >= 40){

        hash_pos = 0;

    }

    while(array[hash_pos] != '*'){

        hash_pos = reHash(hash_pos);

        count++;

        if(count>=40){

            cout<<"Memory Full!!No space is avaible for storage";

            break;

        }

    }

    if(array[hash_pos] == '*'){

        array[hash_pos] = d;

    }

    cout<<"Data is stored at index "<<hash_pos<<endl;

}

int hash::Hash(int key){

    return key%45;

}

int hash::reHash(int key){

    return (key+1)%100;

}

void hash::search(){

    int key,i;

    bool isFound = false;

    cout<<"Enter the key to search: ";

    cin>>key;

    for(i = 0; i < 40; i++){

        if(array[i] == key){

            isFound = true;

            break;

        }

    }

    if(isFound){

        cout<<"The key is found at index "<< i <<endl;

    }else{

        cout<<"No record found!!"<<endl;

    }

}



int main(){

    hash h;

    int choice, value;

    while(1){

        cout<<"\n1. Insert\n2. Search\n3. Exit\n";

        cout<<"Enter your choice: ";

        cin>>choice;

        switch(choice){

            case 1:
     for (int i = 0; i < 150; i++)
     {            
     unsigned seed = time(0);
     srand(seed);
     
     
     value = rand() % 100000 + 899999;
     

                h.insert(value);
     }
                break;

            case 2:

                h.search();

                break;

            case 3:
                 
                 h.printHash();
                 
            case 4:

                exit(0);

            default:

                cout<<"\nEnter correct option\n";

                break;

        }

    }
    system ("pause<nul");
    return 0;

}
