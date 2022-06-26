#include <iostream>
using namespace std;

struct Clock{
    public:
    int hrs =0;
    int mins=0;

    void setTime(unsigned int h, unsigned int m){
        hrs = h;
        mins = m;
    }

    void nextMinute(){
        if(mins==59){
            mins=0;
            hrs++;
        }else{
            mins++;
        }
    }

    void nextHour(){
        if(hrs==23){
            hrs=0;
        }else{
            hrs++;
        }
    }

    void prevMinute(){
        if(mins==0){
            mins=59;
            hrs--;
        }else{
            mins--;
        }
    }
     void addTime(unsigned int h, unsigned int m){
        while(h>0){
            if(hrs==23){
                hrs=0;
            }else{
                hrs++;
            }
            h--;
        }
        while(m>0){
            if(mins==59){
                mins=0;
                hrs++;
            }else{
                mins++;
            }
            m--;
        }
     }

     void currentTime(int format){
        if(format==1){
            int HH = hrs%12;
            if(HH==0){
                HH=12;
            }
            string meredian;
            if(hrs>11){
                meredian="PM";
            }else{
                meredian="AM";
            }
            if(HH>10 && mins>10){
                cout<<HH<<":"<<mins<<" "<<meredian;
            }else if(HH<10 && mins>10){
                cout<<"0"<<HH<<":"<<mins<<" "<<meredian;
            }else if(HH>10 && mins <10){
                cout<<HH<<":"<<"0"<<mins<<" "<<meredian;
            }else{
                cout<<"0"<<HH<<":"<<"0"<<mins<<" "<<meredian;
            }
        }   
        else if(format==2){
            if(hrs>10 && mins>10){
                cout<<hrs<<":"<<mins;
            }else if(hrs<10 && mins>10){
                cout<<"0"<<hrs<<":"<<mins;
            }else if(hrs>10 && mins <10){
                cout<<hrs<<":"<<"0"<<mins;
            }else{
                cout<<"0"<<hrs<<":"<<"0"<<mins;
            }
        }
     }
};

// int main()
// {
//     Clock c1;
//     c1.setTime(22,0);
//     c1.prevMinute();
//     c1.addTime(5,2);
//     c1.currentTime(2);
//     cout<<endl;
//     c1.nextMinute();
//     c1.currentTime(1);
//     return 0;
// }
