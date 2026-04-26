#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class game{
    public:
int r=130, c=200;
string arr[130][200];
ofstream file;
public:
void fileCreating(){
    file.open("game.ppm");
    if(file.is_open()){
        file<<"P3"<<endl;
        file<<c<<" "<<r<<endl;
        file<<"255"<<endl;
    }else{
        cout<<"false"<<endl;
    }
}

void screenCreating(){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            arr[i][j]="0 0 0";
        }
    }
}

void showScreen(){
    for(int i=r-1; i>=0; i--){
        for(int j=0; j<c; j++){
            file<<arr[i][j]<<endl;
        }
    }
}
void RecDATA(){
    int recH, recW, posOfRecX,posOfRecY;
        string color, rgbColorCode, filledData;
        
        cout<<"Enter rectangle height and width:";
        cin>>recH>>recW;
            cout<<"Enter position(x,y) of ractangle on screen:";
        cin>>posOfRecX>>posOfRecY;
        cout<<"Color(red,yellow,blue,white):";
        cin.ignore();
        cin>>color;
        if(color=="red"){
            rgbColorCode="255 0 0";
        }else if(color=="yellow"){
            rgbColorCode="255 255 0";
        }else if(color=="blue"){
            rgbColorCode="0 0 255";
        }else if(color=="white"){
            rgbColorCode="255 255 255";
        }
        cout<<"Filled shape(y/n): ";
        cin>>filledData;
        if(filledData=="n" || filledData=="N"){
            if(posOfRecX+recW<=c && posOfRecY+recH<=r){ //checking validation
        for(int i=posOfRecY; i<=posOfRecY+(recH-1); i++){
            for(int j=posOfRecX; j<=posOfRecX+(recW-1); j++){
                if((i==posOfRecY) && (j<=posOfRecX+(recW-1))){
                    arr[i][j]=rgbColorCode;
                }else if((j==posOfRecX) && (i<=posOfRecY+(recH-1))){
                    arr[i][j]=rgbColorCode;
                }else if(i==posOfRecY+(recH-1) && (j<=posOfRecX+(recW-1))){
                    arr[i][j]=rgbColorCode;
                }else if( (j==posOfRecX+(recW-1)) && (i<=posOfRecY+(recH-1))){
                    arr[i][j]=rgbColorCode;
                }else{

                }
        }
        }
    }else{
        cout<<"Error> Position takes shape out of box"<<endl;
        cout<<"Try again"<<endl;
        RecDATA();
    }
        }else{
        if(posOfRecX+recW<=c && posOfRecY+recH<=r){ //checking validation
        for(int i=posOfRecY; i<=posOfRecY+(recH-1); i++){
            for(int j=posOfRecX; j<=posOfRecX+(recW-1); j++){
            arr[i][j]=rgbColorCode;
        }
        }
    }else{
        cout<<"Error> Position takes shape out of box"<<endl;
        cout<<"Try again"<<endl;
        RecDATA();
    }
}
        }
void incluShapes(){
    int exitSign=0;
    while(exitSign==0){
    int choiceOfShape;
    cout<<"chose a option:"<<endl;
    cout<<"1> for a rectangle"<<endl;
    cout<<"2> for a circle"<<endl;
    cout<<"3> for exit"<<endl;
    cout<<"Enter: ";
    cin>>choiceOfShape;
    if(choiceOfShape==1){
        //rectangle
        RecDATA();

    }else if(choiceOfShape==2){
        //circle
        int radOfCircle;
        int posOfCirX,posOfCirY;
        int h, k;
        string color, rgbColorCode, filledData;
        cout<<"Enter radius of circle: ";
        cin>>radOfCircle;
        cout<<"Enter position(x,y) of circle on screen:";
        cin>>posOfCirX>>posOfCirY;
        h=posOfCirX+radOfCircle+1;
        k=posOfCirY+radOfCircle+1;
        cout<<"Color(red,yellow,blue,white):";
        cin.ignore();
        cin>>color;
        if(color=="red"){
            rgbColorCode="255 0 0";
        }else if(color=="yellow"){
            rgbColorCode="255 255 0";
        }else if(color=="blue"){
            rgbColorCode="0 0 255";
        }else if(color=="white"){
            rgbColorCode="255 255 255";
        }
        cout<<"Filled shape(y/n): ";
        cin>>filledData;
        if(filledData=="y"|| filledData=="Y"){
            for(int i=posOfCirY; i<=posOfCirY+(2*radOfCircle)+5; i++){
            for(int j=posOfCirX; j<=posOfCirX+(2*radOfCircle)+5; j++){  
                if(((i-h)*(i-h)+(j-k)*(j-k))<(radOfCircle*radOfCircle)+30){
                    arr[i][j]=rgbColorCode;
                }
            }
        }
        }else{
            for(int i=posOfCirY; i<=posOfCirY+(2*radOfCircle)+5; i++){
            for(int j=posOfCirX; j<=posOfCirX+(2*radOfCircle)+5; j++){
                if(((i-h)*(i-h)+(j-k)*(j-k))<=(radOfCircle*radOfCircle+30) && ((i-h)*(i-h)+(j-k)*(j-k))>=(radOfCircle*radOfCircle-35) ){
                    arr[i][j]=rgbColorCode;
                }   
            }
        }
        }
    }else if(choiceOfShape==3){
    exitSign=1;
    }else{
        cout<<"Invalid choice!";
    }
}
}
};

int main(){
    game g1;
    g1.fileCreating();
    g1.screenCreating();
    g1.incluShapes();
    g1.showScreen();
    return 0;
}