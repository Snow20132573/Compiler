#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
using namespace std;
char table[128][128];
string VT="+-*/^()i#";
string Input_S,s;//���봮,�ַ�ջ
int stp,k;//stpΪ���봮�Ķ�������
int static cont=0;
char a;//��ǰ�����ַ�
int Len;//lenΪ�����ַ�������
void grammer_display()
{
    cout<<setw(50)<<"grammer"<<endl;
    cout.fill(1);
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout.fill(' ');
    cout<<setw(10)<<VT[0]<<setw(10)<<VT[1]<<setw(10)<<VT[2]<<setw(10)<<VT[3]<<setw(10)<<VT[4]<<setw(10)<<VT[5]<<setw(10)<<VT[6]<<setw(10)<<VT[7]<<setw(10)<<VT[8]<<endl;
    cout<<VT[0]<<setw(9)<<table[VT[0]][VT[0]]<<setw(10)<<table[VT[0]][VT[1]]<<setw(10)<<table[VT[0]][VT[2]]<<setw(10)<<table[VT[0]][VT[3]]<<setw(10)<<table[VT[0]][VT[4]]<<setw(10)<<table[VT[0]][VT[5]]<<setw(10)<<table[VT[0]][VT[6]]<<setw(10)<<table[VT[0]][VT[7]]<<setw(10)<<table[VT[0]][VT[8]]<<endl;
    cout<<VT[1]<<setw(9)<<table[VT[1]][VT[0]]<<setw(10)<<table[VT[1]][VT[1]]<<setw(10)<<table[VT[1]][VT[2]]<<setw(10)<<table[VT[1]][VT[3]]<<setw(10)<<table[VT[1]][VT[4]]<<setw(10)<<table[VT[1]][VT[5]]<<setw(10)<<table[VT[1]][VT[6]]<<setw(10)<<table[VT[1]][VT[7]]<<setw(10)<<table[VT[1]][VT[8]]<<endl;
    cout<<VT[2]<<setw(9)<<table[VT[2]][VT[0]]<<setw(10)<<table[VT[2]][VT[1]]<<setw(10)<<table[VT[2]][VT[2]]<<setw(10)<<table[VT[2]][VT[3]]<<setw(10)<<table[VT[2]][VT[4]]<<setw(10)<<table[VT[2]][VT[5]]<<setw(10)<<table[VT[2]][VT[6]]<<setw(10)<<table[VT[2]][VT[7]]<<setw(10)<<table[VT[2]][VT[8]]<<endl;
    cout<<VT[3]<<setw(9)<<table[VT[3]][VT[0]]<<setw(10)<<table[VT[3]][VT[1]]<<setw(10)<<table[VT[3]][VT[2]]<<setw(10)<<table[VT[3]][VT[3]]<<setw(10)<<table[VT[3]][VT[4]]<<setw(10)<<table[VT[3]][VT[5]]<<setw(10)<<table[VT[3]][VT[6]]<<setw(10)<<table[VT[3]][VT[7]]<<setw(10)<<table[VT[3]][VT[8]]<<endl;
    cout<<VT[4]<<setw(9)<<table[VT[4]][VT[0]]<<setw(10)<<table[VT[4]][VT[1]]<<setw(10)<<table[VT[4]][VT[2]]<<setw(10)<<table[VT[4]][VT[3]]<<setw(10)<<table[VT[4]][VT[4]]<<setw(10)<<table[VT[4]][VT[5]]<<setw(10)<<table[VT[4]][VT[6]]<<setw(10)<<table[VT[4]][VT[7]]<<setw(10)<<table[VT[4]][VT[8]]<<endl;
    cout<<VT[5]<<setw(9)<<table[VT[5]][VT[0]]<<setw(10)<<table[VT[5]][VT[1]]<<setw(10)<<table[VT[5]][VT[2]]<<setw(10)<<table[VT[5]][VT[3]]<<setw(10)<<table[VT[5]][VT[4]]<<setw(10)<<table[VT[5]][VT[5]]<<setw(10)<<table[VT[5]][VT[6]]<<setw(10)<<table[VT[5]][VT[7]]<<setw(10)<<table[VT[5]][VT[8]]<<endl;
    cout<<VT[6]<<setw(9)<<table[VT[6]][VT[0]]<<setw(10)<<table[VT[6]][VT[1]]<<setw(10)<<table[VT[6]][VT[2]]<<setw(10)<<table[VT[6]][VT[3]]<<setw(10)<<table[VT[6]][VT[4]]<<setw(10)<<table[VT[6]][VT[5]]<<setw(10)<<table[VT[6]][VT[6]]<<setw(10)<<table[VT[6]][VT[7]]<<setw(10)<<table[VT[6]][VT[8]]<<endl;
    cout<<VT[7]<<setw(9)<<table[VT[7]][VT[0]]<<setw(10)<<table[VT[7]][VT[1]]<<setw(10)<<table[VT[7]][VT[2]]<<setw(10)<<table[VT[7]][VT[3]]<<setw(10)<<table[VT[7]][VT[4]]<<setw(10)<<table[VT[7]][VT[5]]<<setw(10)<<table[VT[7]][VT[6]]<<setw(10)<<table[VT[7]][VT[7]]<<setw(10)<<table[VT[7]][VT[8]]<<endl;
    cout<<VT[8]<<setw(9)<<table[VT[8]][VT[0]]<<setw(10)<<table[VT[8]][VT[1]]<<setw(10)<<table[VT[8]][VT[2]]<<setw(10)<<table[VT[8]][VT[3]]<<setw(10)<<table[VT[8]][VT[4]]<<setw(10)<<table[VT[8]][VT[5]]<<setw(10)<<table[VT[8]][VT[6]]<<setw(10)<<table[VT[8]][VT[7]]<<setw(10)<<table[VT[8]][VT[8]]<<endl;
    cout.fill(1);
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;
    cout<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<setw(10)<<"!"<<endl;

}
void init()
{
    for(int i=0; i<128; i++)
        for(int j=0; j<128; j++)
            table[i][j]=' ';
    table['+']['+']='>';
    table['+']['-']='>';
    table['+']['*']='<';
    table['+']['/']='<';
    table['+']['^']='<';
    table['+']['(']='<';
    table['+'][')']='>';
    table['+']['i']='<';
    table['+']['#']='>';

    table['-']['+']='>';
    table['-']['-']='>';
    table['-']['*']='<';
    table['-']['/']='<';
    table['-']['^']='<';
    table['-']['(']='<';
    table['-'][')']='>';
    table['-']['i']='<';
    table['-']['#']='>';

    table['*']['+']='>';
    table['*']['-']='>';
    table['*']['*']='>';
    table['*']['/']='>';
    table['*']['^']='<';
    table['*']['(']='<';
    table['*'][')']='>';
    table['*']['i']='<';
    table['*']['#']='>';

    table['/']['+']='>';
    table['/']['-']='>';
    table['/']['*']='>';
    table['/']['/']='>';
    table['/']['^']='<';
    table['/']['(']='<';
    table['/'][')']='>';
    table['/']['i']='<';
    table['/']['#']='>';

    table['^']['+']='>';
    table['^']['-']='>';
    table['^']['*']='>';
    table['^']['/']='>';
    table['^']['^']='<';
    table['^']['(']='<';
    table['^'][')']='>';
    table['^']['i']='<';
    table['^']['#']='>';

    table['(']['+']='<';
    table['(']['-']='<';
    table['(']['*']='<';
    table['(']['/']='<';
    table['(']['^']='<';
    table['(']['(']='<';
    table['('][')']='=';
    table['(']['i']='<';
    table['(']['#']=' ';

    table[')']['+']='>';
    table[')']['-']='>';
    table[')']['*']='>';
    table[')']['/']='>';
    table[')']['^']='>';
    table[')']['(']=' ';
    table[')'][')']='>';
    table[')']['i']=' ';
    table[')']['#']='>';

    table['i']['+']='>';
    table['i']['-']='>';
    table['i']['*']='>';
    table['i']['/']='>';
    table['i']['^']='>';
    table['i']['(']=' ';
    table['i'][')']='>';
    table['i']['i']=' ';
    table['i']['#']='>';

    table['#']['+']='<';
    table['#']['-']='<';
    table['#']['*']='<';
    table['#']['/']='<';
    table['#']['^']='<';
    table['#']['(']='<';
    table['#'][')']=' ';
    table['#']['i']='<';
    table['#']['#']='=';
    stp=0;
    k=0;
    s[k]='#';
    a=Input_S[stp];
}
bool Is_VT(char xx)
{
    for(int i=0; i<9; i++)
        if(xx==VT[i])
            return true;
    return false;
}
void display()//�����ͷ
{
    cout<<"\t\t\t\t\t������\n\n\n";
    cout.fill(' ');
    //cout<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!"<<setw(20)<<"!\n";
    cout<<setw(20)<<"����"<<setw(20)<<"ջ"<<setw(20)<<"���ȹ�ϵ"<<setw(20)<<"��ǰ����"<<setw(25)<<"ʣ�����봮"<<setw(20)<<"�ƽ����Լ\n";
    cout.fill(' ');
}
void Algorithm()
{
    //cout<<"######################"<<stp<<"############"<<endl;

    char Q;
    int i;
    bool GY=false;//��־��Լ�����ƽ�
    string temp,temps;//��ʱ��Լ��
    int j,t=0;
//    for(int i=stp+1;i<Input_S.length();i++)//ʣ���������
//        temp[t++]=Input_S[i];
//    temp[t]='\0';
//    for(i=0;i<=k;i++)//ջ
//            temps[i]=s[i];
//    temps[i]='\0';
//    cout<<temp<<endl;
//    cout<<temps<<endl;
    bool b=Is_VT(s[k]);//�����ǰջ�����ս����j=k,����j=k-1
    cont++;//����+1
    if(b)
        j=k;
    else
        j=k-1;
    if(cont!=1)
        a=Input_S[stp];//��ǰ�����ַ���a
    //cout<<"ջ������"<<s[j]<<"��ǰ����"<<a<<endl;
    cout<<setw(20)<<cont;
    if(cont<=9)
            cout<<setw(20);
        else
            cout<<setw(20);
    if(s[j]>a)//��ǰ�����ַ����ȼ��ϵͣ��������Ҫ��Լ
    {
        for(i=0;i<=k;i++)
        {
            temps[i]=s[i];
            cout<<temps[i];
        }
        temps[i]='\0';
        cout<<setw(20-i)<<table[s[j]][a];
        //cout<<temps<<endl;
        //cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
        Q=s[j];
        while(s[j]>=Q)//�ҵ���Լ���ַ���
        {
            Q=s[j];
            if(Is_VT(s[j-1]))
                j--;
            else
                j-=2;
        }
        GY=true;//�ҵ���Ҫ��Լ���ַ���
        cout<<setw(20)<<a<<setw(20);
        for(i=stp+1,t=0;i<Len;t++,i++)
        {
            temp[t]=Input_S[i];
             cout<<temp[t];
        }
        k=j+1;
        s[k]='N';
        s[k+1]='\0';
        if(stp+1>=Len)
            cout<<setw(40);
        else
            cout<<setw(21-t);
        cout<<"��Լ\n";
        Algorithm();
    }
    else//������Ҫ�ƽ�
    {
        //cout<<"********************************"<<a<<endl;

        for(i=0;i<=k;i++)
         {
             temps[i]=s[i];
             cout<<temps[i];
         }
         cout<<setw(20-i)<<table[s[j]][a]<<setw(20)<<a;
        cout<<setw(20);
        for(i=stp+1;i<Len;i++)
            cout<<Input_S[i];
        if(s[j]<a)//��ǰ�����ַ����ȼ��ͣ��ƽ�
        {
            k++;
            s[k]=a;
            stp++;
        }else{
            if(s[j]==a){
                if(s[j]=='#'){
                    if(stp+1==Len){
                        cout<<setw(39)<<"����\n\n\n\t\t\t��ϲŮ�����ˣ�����ı��ʽ��ȫ�����ķ�Ŷ������Ŭ��Ŷ��\n\n"<<endl;
                        return ;
                    }else{
                        cout<<"ERROR\n\n\t\t\t����ɣ~~~Ů�����˳�����"<<endl;
                        return ;
                    }
                }else{
                    k++;
                    s[k]=a;
                    stp++;
                }
            }else{
                cout<<"ERROR\n\n\t\t\t����ɣ~~~Ů�����˳�����"<<endl;
                return ;
                //cout<<"*************111"<<endl;
            }
        }
        cout<<setw(20-Len+stp+1)<<"�ƽ�\n";
        Algorithm();
    }

//    cout<<setw(20)<<temps<<setw(20)<<table[s[j]][a]<<setw(20)<<a<<setw(20)<<temp;//������ȹ�ϵ��ǰ����
//    if(GY)
//       cout<<setw(20)<<"��Լ"<<endl;
//    else
//        cout<<setw(20)<<"�ƽ�"<<endl;
    //Algorithm();
}
void function()
{

    cont=0;
    cout<<"Ů������������ϲ���ı��ʽ"<<endl;
    cin>>Input_S;
    init();
    grammer_display();
    Len=Input_S.length();
    display();
    Algorithm();
    function();
}
int main()
{
    cout<<"\t\t\t��������ķ�\n\n\n";
    function();
    return 0;
}
