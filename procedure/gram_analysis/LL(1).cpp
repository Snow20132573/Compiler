#include<iomanip>
#include<iostream>
using namespace std;
string str[128][128],s,Sta;//str�����������SΪ���봮�ַ�,staΪ��ǰ�ַ�ջ
string VT="i+*()#-/";//�ս��
string VN="EATBF";//���ս��
int LVT,LVN,stp,top;
static int count=0;
char a,x;//a�������봮��ǰ�ַ���x����ջ������

void init()//��ʼ��
{
    LVT=VT.length();
    LVN=VN.length();
    for(int i=0; i<128; i++) //������ֵΪ�մ�
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
    stp=0;//�����ַ���ɨ����ʼ��
    top=0;//��ǰ��ջ��
    Sta[top++]='#';
    Sta[top++]='E';//#��E��ջ
    a=s[stp];//��¼���봮��ǰ�ַ�
}
void play_grammer()//�ķ�������
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
void display()//�����ͷ
{

    cout<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!\n";
    cout<<"����"<<setw(20)<<"����ջ"<<setw(20)<<"ʣ�����봮"<<setw(30)<<"�Ƶ����ò���ʽ��ƥ��\n";
    cout.fill(' ');
}
void algorithm()//�㷨
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
                cout<<a<<"ƥ��\n";
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
