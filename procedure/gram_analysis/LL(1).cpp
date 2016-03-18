#include<iomanip>
#include<iostream>
using namespace std;
string str[128][128],s,Sta;//str数组用来存表，S为输入串字符,sta为当前字符栈
string VT="i+*()#-/";//终结符
string VN="EATBF";//非终结符
int LVT,LVN,stp,top;
static int count=0;
char a,x;//a代表输入串当前字符，x代表栈顶符号

void init()//初始化
{
    LVT=VT.length();
    LVN=VN.length();
    for(int i=0; i<128; i++) //给表赋初值为空串
        for(int j=0; j<128; j++)
            str[i][j]="";
    str['E']['i']="TA\0";
    str['E']['(']="TA\0";

    str['A']['+']="+TA\0";
    str['A']['-']="-TA\0";
    str['A'][')']="@\0";
    str['A']['#']="@\0";

    str['T']['i']="FB\0";
    str['T']['(']="FB\0";

    str['B']['*']="*FB\0";
    str['B']['/']="/FB\0";
    str['B']['+']="@\0";
    str['B'][')']="@\0";
    str['B']['#']="@\0";
    str['B']['-']="@\0";

    str['F']['i']="i\0";
    str['F']['(']="(E)\0";
    stp=0;//输入字符串扫描起始点
    top=0;//当前符栈顶
    Sta[top++]='#';
    Sta[top++]='E';//#和E进栈
    a=s[stp];//记录输入串当前字符
}
void play_grammer()//文法分析表
{
    //cout.setlinesize(150);
    cout<<setw(50)<<"(~~~~~~grammer~~~~~)\n\n\n";
    cout.fill('=');
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!\n";
    cout.fill(' ');
    cout<<setw(10)<<VT[0]<<setw(10)<<VT[1]<<setw(10)<<VT[2]<<setw(10)<<VT[3]<<setw(10)<<VT[4]<<setw(10)<<VT[5]<<setw(10)<<VT[6]<<setw(10)<<VT[7]<<endl;
    cout<<"========================================================================================\n";
    cout<<VN[0]<<setw(10)<<str[VN[0]][VT[0]]<<setw(10)<<str[VN[0]][VT[1]]<<setw(10)<<str[VN[0]][VT[2]]<<setw(10)<<str[VN[0]][VT[3]]<<setw(10)<<str[VN[0]][VT[4]]<<setw(10)<<str[VN[0]][VT[5]]<<setw(10)<<str[VN[0]][VT[6]]<<setw(10)<<str[VN[0]][VT[7]]<<endl;
    cout<<VN[1]<<setw(10)<<str[VN[1]][VT[0]]<<setw(10)<<str[VN[1]][VT[1]]<<setw(10)<<str[VN[1]][VT[2]]<<setw(10)<<str[VN[1]][VT[3]]<<setw(10)<<str[VN[1]][VT[4]]<<setw(10)<<str[VN[1]][VT[5]]<<setw(10)<<str[VN[1]][VT[6]]<<setw(10)<<str[VN[1]][VT[7]]<<endl;
    cout<<VN[2]<<setw(10)<<str[VN[2]][VT[0]]<<setw(10)<<str[VN[2]][VT[1]]<<setw(10)<<str[VN[2]][VT[2]]<<setw(10)<<str[VN[2]][VT[3]]<<setw(10)<<str[VN[2]][VT[4]]<<setw(10)<<str[VN[2]][VT[5]]<<setw(10)<<str[VN[2]][VT[6]]<<setw(10)<<str[VN[2]][VT[7]]<<endl;
    cout<<VN[3]<<setw(10)<<str[VN[3]][VT[0]]<<setw(10)<<str[VN[3]][VT[1]]<<setw(10)<<str[VN[3]][VT[2]]<<setw(10)<<str[VN[3]][VT[3]]<<setw(10)<<str[VN[3]][VT[4]]<<setw(10)<<str[VN[3]][VT[5]]<<setw(10)<<str[VN[3]][VT[6]]<<setw(10)<<str[VN[3]][VT[7]]<<endl;
    cout<<VN[4]<<setw(10)<<str[VN[4]][VT[0]]<<setw(10)<<str[VN[4]][VT[1]]<<setw(10)<<str[VN[4]][VT[2]]<<setw(10)<<str[VN[4]][VT[3]]<<setw(10)<<str[VN[4]][VT[4]]<<setw(10)<<str[VN[4]][VT[5]]<<setw(10)<<str[VN[4]][VT[6]]<<setw(10)<<str[VN[4]][VT[7]]<<endl;
    cout.fill('=');
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!\n\n\n\n\n";
}
void display()//输出表头
{

    cout<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!\n";
    cout<<"步骤"<<setw(20)<<"分析栈"<<setw(20)<<"剩余输入串"<<setw(30)<<"推导所用产生式或匹配\n";
    cout.fill(' ');
}
void algorithm()//算法
{
    int f=0,t,y;
    string k,q;
    x=Sta[--top];
    a=s[stp];
    count++;
    cout<<count<<setw(20);
    if(count>=10)
        cout<<"\b";
    for(y=0;y<=top;y++)
        cout<<Sta[y];
    cout<<setw(20-top);
    for(int j=0; j<LVT; j++)
    {
        if(x==VT[j])
        {
            f=1;
            break;
        }
    }
    if(f==1&&a!='#')
    {
        if(x==a)
        {
            //stp++;
            if(stp<s.length())
            {
                //cout<<s[stp-1];
                for(y=stp;y<s.length();y++)
                    cout<<s[y];
                cout<<setw(20-s.length()+stp);
                cout<<a<<"匹配\n";
                stp++;
                algorithm();
            }

            return;
        }
        else
        {
            cout<<"Error!!!\n";
        }
    }
    else
    {
        //cout<<"*********************************\n";
        if(x=='#')
        {
            if(x==a)
            {
                cout<<"#";
                cout<<setw(29);
                cout<<"Success!!!\n\n\n\n\t\t\t\tCongratulations";
                cout<<""<<endl;
                return;
            }
            else
            {
                cout<<"Error!!!\n";
            }
        }
        else
        {
            if(str[x][a].length()==0)
            {
                cout<<"Error!!!\n";
            }
            else
            {
                for(y=stp;y<s.length();y++)
                    cout<<s[y];
                cout<<setw(20-s.length()+stp);
                string xx=str[x][a];
                cout<<x<<"->"<<xx<<endl;
                int len=xx.length()-1;
                if(xx=="@")
                {
                    algorithm();
                    return;
                }
                for(; len>=0; len--)
                {
                    Sta[top++]=xx[len];
                }
                algorithm();
            }
        }
    }

}
void function()
{
    init();
    play_grammer();
    cin>>s;
    display();
    algorithm();
}
int main()
{
    while(1){
        function();
        count=0;
    }
    return 0;
}
