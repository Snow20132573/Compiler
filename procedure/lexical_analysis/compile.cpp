#include<cstring>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<iomanip>
#include<sstream>
using namespace std;
//�ؼ���
char* key[]= {"if","else","for","while","do","return","int","void","main","break","continue","cout","float"};
//��ʶ��
struct name
{
    char ID[20];
} name[1000];
int namenum=0;//��ʶ������
//�����
char* operate[]= {"%","+","#","-","*","/",">","<","=","++","--",">=","<=","==","!=","&&","||"};
//�ֽ��
char* border[]= {",",";","{","}","(",")","[","]"};
//����
struct num
{
    int num1;
    float num2;
    bool x1;//trueʱnum1����
    bool x2;//trueʱnum2����
} num[1000];
int numbernum=0;//��������
char* f1name="f1.txt";//��Ԫ���
char* f2name="f2.txt";//������
char* f3name="f3.txt";//��ʶ����
FILE* f1,*f2,*f3;//���ű�
int x;//��ȡ���ַ���λ��
int i,j,k,f=0,len;
char A[20];//������ʱ����ַ���
string getsym="";//��ʼʱû�ж����������ǿմ�
string Array[100000];
int length;//����ĳ���
int Len=0;//Array����ĳ���
struct Siyuan
{
    string op;
    string w1;
    string w2;
    string step;
}Si[1000];
struct Goal
{
    int step;
    string G1;
    string G2;
    string G3;
}Goal[1000];
int Begin=1,END=2000,start=1;
void Read_file(char* s,string &getsym)
{
    FILE *fp;
    if((fp=fopen(s,"r"))!=NULL)
    {
        while(!feof(fp))//��ȡ����getsym��
        {
            getsym+=fgetc(fp);
        }
    }
    cout<<getsym<<endl;
    fclose(fp);
}
void openfile()
{
    f1=fopen(f1name,"a");
    if(!f1)
    {
        f1=fopen(f1name,"w");
    }
    char* sm="1.�ؼ���2.��ʶ��3.����4.�����5.���";//��Ԫ���ͷ
    fputs(sm,f1);//���Ԫ���ͷ
    f2=fopen(f2name,"a");
    if(!f2)
    {
        f2=fopen(f2name,"w");
    }
    f3=fopen(f3name,"a");
    if(!f3)
    {
        f3=fopen(f1name,"w");
    }
}
void closefile()
{
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
void delete_blank()//�˵��ո񡢻��С�Tab
{
    //cout<<x<<length<<endl;
    while(x<length&&(getsym[x]==' '||getsym[x]==9||getsym[x]==10))
        x++;

}
void character()//�����ǰ����ĸ
{
    k=0;//��ʾ���ʴ��ĳ���
    f=0;
    do
    {
        if(k<10)
            A[k++]=getsym[x++];
    }
    while(x<length&&(getsym[x]>='a'&&getsym[x]<='z'||getsym[x]>='0'&&getsym[x]<='9'));
    //strcpy(id,A);

    for(j=0; j<13; j++)
    {
        //string str(key[j]);
        if(strcmp(A,key[j])==0)
        {
            f=1;//�ҵ�ƥ��Ĺؼ���
            break;
        }
    }
    //cout<<A<<endl;
    if(f)//A�ǹؼ���,д���Ԫ��
    {
        fputs("\n",f1);
        fputs(A,f1);
        string a(A);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("1",f1);
    }
    else//A�Ǳ�ʶ��
    {
        //***��ʶ��д���Ԫ��***************************
        fputs("\n",f1);
        fputs(A,f1);
        string a(A);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("2",f1);

        //****�״γ��ֵı�ʶ��д���ʶ����********************
        int p=0;
        for(int e=0; e<namenum; e++) //���ұ�ʶ���Ƿ���ֹ�
            if(strcmp(name[e].ID,A)==0)
            {
                p=1;
                break;
            }

        if(!p)
        {

            strcpy(name[namenum++].ID,A);
            fputs("\n",f2);
            fputs(A,f2);
        }
    }
}
void Number()//������
{

    int start=x,end;//��¼���ʴ��Ŀ�ʼ�ͽ�β
    float number=0,number1=0;//number1��ʱ����С������
    do
    {
        number=10*number+getsym[x++]-'0';
    }
    while(x<length&&getsym[x]>='0'&&getsym[x]<='9');
    if(getsym[x]=='.')//��ʱΪ������
    {
        x++;
        do
        {
            number1=number1/10+getsym[x++]-'0';
        }
        while(x<length&&getsym[x]>='0'&&getsym[x]<='9');
        number+=number1;
        num[numbernum].num2=number;
        num[numbernum++].x2=true;
        //cout<<number<<endl;
    }
    else//��ʱΪ����
    {
        num[numbernum].num1=(int)number;
        num[numbernum++].x1=true;
        //cout<<number<<endl;
    }
    end=x;
    memset(A,'\0',20*sizeof(char));
    for(int y=start,k=0; y<end; y++,k++)
        A[k]=getsym[y];
    fputs("\n",f3);
    fputs(A,f3);//������д�볣����
    //***������д���Ԫ��
    fputs("\n",f1);
    fputs(A,f1);
    string a(A);
    len=a.size();
    int ll=15-len;
    for(int t=0; t<ll; t++)
        fputs(" ",f1);
    fputs("3",f1);

}
void Border()
{
    //***���ֽ��д���Ԫ��
    fputs("\n",f1);
    fputs(border[i],f1);
    //strcpy(id,border[i]);
    string a(border[i]);
    len=a.size();
    int ll=15-len;
    for(int t=0; t<ll; t++)
        fputs(" ",f1);
    fputs("5",f1);
    x++;
    //cout<<border[i]<<endl;
}
//*****************************************************************

void Operate()
{
    //***�жϵ�ǰ�ǲ����������ŵ������
    //cout<<"**********************1\n";
    memset(A,'\0',20*sizeof(char));
    f=0;
    for(i=9; i<17; i++)
    {
        //char* h;
        A[0]=getsym[x];
        if(x+1<length)
            A[1]=getsym[x+1];
        //cout<<A<<endl;
        if(strcmp(A,operate[i])==0)
        {
            f=1;
            break;
        }
    }
    if(f)//***��ǰ��һ�����ŵ������
    {
        //***��һ�����ŵ������д���Ԫ��
        fputs("\n",f1);
        fputs(operate[i],f1);
        //strcpy(id,operate[i]);
        string a(operate[i]);
        len=a.size();
        int ll=15-len;
        for(int t=0; t<ll; t++)
            fputs(" ",f1);
        fputs("4",f1);
        x+=2;
        //cout<<operate[i]<<endl;
    }
    else//***��ǰ���������ŵ�����������������Ĺ涨֮��ķ���
    {
        f=0;
        memset(A,'\0',20*sizeof(char));
        A[0]=getsym[x];
        for(i=0; i<9; i++)
        {
            if(strcmp(A,operate[i])==0)
            {
                f=1;
                break;
            }
        }
        //cout<<A<<endl;
        if(f)//***��ǰ���������ŵ������
        {
            //***���������ŵ������д���Ԫ��
            fputs("\n",f1);
            fputs(operate[i],f1);
            //strcpy(id,operate[i]);
            string a(operate[i]);
            len=a.size();
            int ll=15-len;
            for(int t=0; t<ll; t++)
                fputs(" ",f1);
            fputs("4",f1);
            x++;
            //cout<<operate[i]<<endl;
        }
    }
}
///***************************************************************

void getSym()
{

    openfile();//���ļ�
    for(x=0; x<=length-1;)
    {
        //cout<<getsym[82]<<endl;
        f=0;//��־������ʼ��
        memset(A,'\0',20*sizeof(char));
        delete_blank();
        //*************�жϵ�ǰ�ǲ�����ĸ
        if(x<length&&getsym[x]>='a'&&getsym[x]<='z')
            character();
        else//��ǰ���ʴ�������ĸ��ͷ����x>=length
        {

            if(x>=length)
                break;
            else if(getsym[x]>='0'&&getsym[x]<='9')//����Ƿ�������0����9��ͷ
                Number();
            else//��ǰ�ַ����ǹؼ���/��ʶ��/����
            {
                //***�жϵ�ǰ�ǲ��Ƿֽ��*********

                f=0;
                memset(A,'\0',20*sizeof(char));
                A[0]=getsym[x];
                for(i=0; i<8; i++)
                {
                    if(strcmp(A,border[i])==0)
                    {
                        f=1;
                        break;
                    }
                }
                if(f)//��ǰ�Ƿֽ��
                {
                    Border();
                    if(x==length-1)
                        break;
                }
                else//��ǰ���Ƿֽ��������������ߴ������
                {
                    //cout<<"*********************1\n";
                    Operate();
                    //cout<<"*********************2\n";
                }

            }

        }
    }
    closefile();
}
void Read_filef1(char* s)
{
    FILE* fp;
    int f;
    char c;
    string Prog="";
    if((fp=fopen(s,"r"))!=NULL)
    {
        fseek(fp,38,0);//���˿�ʼ�ı�־
        while(!feof(fp))//���˿ո�س�����ÿ�����ʷ�������
        {
            c=fgetc(fp);
            if(c!=' '&&c!='\n')
                Prog+=c;
            else
            {
                while(c==' '||c=='\n')
                    c=fgetc(fp);
                Prog+='\0';
                Array[Len++]=Prog;
                Prog="";
                Prog+=c;
            }
        }
        Array[Len++]=Prog;
    }
    fclose(fp);
    for(int j=0;j<Len;j++)
        cout<<Array[j]<<endl;
}
char procede(char theta1,char theta2)//�Ƚ��ַ������ȼ�
{
    int row,col;
    char ch[10]="%=+-*/()#";
    char R[9][10]={{">>>>>><>>"},{"</<<<<</>"},{"</>><<<>>"},{"</>><<<>>"},{">/>>>><>>"},{">/>>>><>>"},{"</<<<<<=/"},{">/>>>>/>>"},{"<<<<<<</="}};
    for(int i=0;i<9;i++)
        if(ch[i]==theta1)
        {
            row=i;
            break;
        }
    for(int i=0;i<9;i++)
        if(ch[i]==theta2)
        {
            col=i;
            break;
        }
    if(row<9&&col<9)
        return R[row][col];
    else
        return '/';
}
bool Is_ZM(char c)
{
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'))
        return true;
    return false;
}
void CLEAR(stack<char> sta)
{
    while(!sta.empty())
        sta.pop();
}
void Num_Str(int x,string& mm)
{
    int c=0;
    char* sss;
    while(1)
    {
       sss[c++]=(x%10)+'0';
       x=x/10;
       if(x==0)
            break;
    }
    c--;
    for(;c>=0;)
        mm+=sss[c--];
    //cout<<mm<<endl;
}
void Biaodashi(string infixexp)//��ɱ��ʽ����Ԫʽ
{
    //infixexp=infixexp.substr(2);
    infixexp+='#';
    //cout<<infixexp<<endl;
    stack<char> s;
    stack<char> sp;
    CLEAR(s);
    CLEAR(sp);
    char w,topelement;
    int i=0,j=0,h=0;
    s.push('#');
    w=infixexp[i];
    while(!s.empty())
    {
        //string y,y1,y2;
        //cout<<"w = "<<w<<endl;
        if(Is_ZM(w))
        {
            //cout<<"sp.top()="<<w<<endl;
            sp.push(w);
            i=i+2;
            w=infixexp[i];
        }
        else
        {
            topelement=s.top();
            switch(procede(topelement,w))
            {
                case '>':
                    {
                         string y="",y1="",y2="";
                         char c,c1,c2;
                         c=s.top();
                         y+=c;
                         s.pop();
                         //cout<<"****************8\n";
                         c1=sp.top();
                         y1+=c1;
                         sp.pop();
                         //cout<<"****************9\n";
                         c2=sp.top();
                         y2+=c2;
                         sp.pop();
                         //cout<<" y1.length ="<<y1.length()<<endl;
                         //cout<<"y1="<<y1<<"  y2="<<y2<<endl;
                         Si[Begin].op=y;
                         Si[Begin].w1=y1;
                         if(c=='=')
                         {
                             Si[Begin].w2="-";
                             Si[Begin++].step=y2;
                         }
                         else
                         {
                             Si[Begin].w2=y2;
                             //Num_Str(Begin+1,u);
                             Si[Begin++].step='A'+h;
                             sp.push('A'+h);
                             h++;
                         }
                         break;
                    }
                case '=':{

                         s.pop();
                         if(w!='#')
                         {
                             i=i+2;
                             w=infixexp[i];
                         }

                         break;
                }
                case '<':{//cout<<"****************3\n";
                         s.push(w);
                         i=i+2;
                         w=infixexp[i];
                         break;
                }
                case '/':cout<<"************4\n";
                         break;
                default:cout<<"��׺���ʽ�Ƿ�"<<endl;
            }

        }
    }
    //cout<<postfixexp<<endl;
}
void cout_Si(int i)
{
    cout<<"("<<i<<")";
    if(i>0&&i<=9)
        cout<<"  "<<setw(5);
    else if(i>=10&&i<=99)
        cout<<"  "<<setw(4);
    else
        cout<<setw(3);
    cout<<Si[i].op<<","<<Si[i].w1<<"   ,"<<Si[i].w2<<"   ,"<<Si[i].step<<endl;//����ж�����һ�����Ϊ��ʱ

}
void Manage_if(int L,int R,int M)//LΪ���ʽ����ߣ�RΪif�Ľ�������M����else�Ľ�����
{
    //cout<<"***************2\n";
    Si[Begin].op=Array[L+2];
    Si[Begin].w1=Array[L];
    Si[Begin].w2=Array[L+4];
    string yy="";
    //cout<<Begin<<endl;
    Num_Str(Begin+2,yy);
    yy+='\0';
    //cout<<yy<<endl;
    Si[Begin].step=yy;
    cout_Si(Begin++);
    //cout<<"("<<Begin++<<")"<<setw(5)<<"( "<<Array[L+2]<<","<<Array[L]<<","<<Array[L+4]<<Begin+1<<")"<<endl;//����ж�����һ�����Ϊ��ʱ
    Si[Begin].op="J--";
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    int m=Begin++;//��¼���ʽΪ��ʱ����Ԫʽ
    L=L+10;
    while(L<R)//���Ϊ��ʱ�Ĵ���
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        //cout<<exp1<<endl;
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }


    Si[Begin].op="J-";//���Ϊ������ִ�����Ҫ����ȥ
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    int nn=Begin++;
    yy="";
    Num_Str(Begin,yy);
    yy+='\0';
    //cout<<"Begin ="<<Begin<<"yy ="<<yy<<endl;
    Si[m].step=yy;//���Ϊ�洦�����֪�������Ϊ��ʱҪ������ȥ
    L=L+8;
    while(Array[L][0]!='}')
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }
    yy="";
    Num_Str(Begin,yy);
    yy+='\0';
    //cout<<"Begin ="<<Begin<<yy<<endl;
    Si[nn].step=yy;
    for(int i=m;i<Begin;i++)
        cout_Si(i);
}

void Manage_While(int l,int r)
{
    int i=l+4;
    int m=Begin;
    Si[Begin].op=Array[i+2];
    Si[Begin].w1=Array[i];
    Si[Begin].w2=Array[i+4];
    string mm="";
    Num_Str(Begin+2,mm);
    Si[Begin].step=mm;//whileΪ��ʱ
    cout_Si(Begin++);

    Si[Begin].op="J--";//whileΪ��ʱ
    Si[Begin].w1="-";
    Si[Begin].w2="-";
    m=Begin++;
    int L=i+10;
    while(Array[L][0]!='}')
    {
        string exp1="";
        while(Array[L][0]!=';')
        {
            exp1+=Array[L];
            L=L+2;
        }
        Biaodashi(exp1);
        if(Array[L+2][0]=='}')
            break;
        else
            L=L+2;
    }
    mm="";
    Num_Str(Begin,mm);
    Si[m].step=mm;
    for(i=m;i<Begin;i++)
        cout_Si(i);
}
void Expression()
{
    cout<<"��Ԫʽ��\n";
    for(int i=10;i<Len;)
    {
        if(Array[i+1][0]=='1')//��ʾ�ǹؼ���
        {
            //cout<<"***************3\n";
            switch (Array[i][0])
            {
                //cout<<"***************2\n";
            case 'i'://��ʱΪint ,if
                if(Array[i][1]=='n')
                {

                    Si[Begin].op="int";
                    Si[Begin].w1="-";
                    Si[Begin].w2="-";
                    Si[Begin].step=Array[i+2];
                    //cout<<"("<<Begin++<<")"<<setw(5)<<"---,--,--,"<<Array[i+2]<<endl;//�������ĵ�һ�����
                    cout_Si(Begin++);
                    i=i+6;
                    while(Array[i][0]!=';')
                    {
                        if(Array[i][0]==',')
                            i=i+2;
                        Si[Begin].op="int";
                        Si[Begin].w1="-";
                        Si[Begin].w2="-";
                        Si[Begin].step=Array[i];
                        //cout<<"("<<Begin++<<")"<<setw(5)<<"---,--,--,"<<Array[i+2]<<endl;
                        cout_Si(Begin++);
                        i=i+2;
                    }
                    i=i+2;
                }
                else
                {

                    int L=i+4,R,M,j;
                    for(j=i+6;Array[j][0]!='}';j++);
                    R=j-1;
                    for(j=j+6;Array[j][0]!='}';j++);
                    M=j-1;
                    Manage_if(L,R,M);//����if���
                    i=M+3;
                }
                break;
            case 'w':
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$$$46\n";
                int j,r;
                for(j=i;Array[j][0]!='}';j++);
                r=j-1;
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$1\n";
                Manage_While(i,r);
                //cout<<"$$$$$$$$$$$$$$$$$$$$$$2\n";
                i=j+2;
                break;
            case 'r':
                return ;
            }

        }
        else if(Array[i+1][0]=='2')//��ʶ��
        {
            //cout<<"***************5";
            string exp1="";
            while(Array[i][0]!=';')
            {
                exp1+=Array[i];
                i=i+2;
            }
            int x=Begin;
            Biaodashi(exp1);
            for(int i=x;i<Begin;i++)
                cout_Si(i);
            i=i+2;
            //cout<<Array[i]<<endl;
        }
        //cout<<"!!!!!!!!!!!";
    }
}
/********************************����Ԫʽд���ļ�***************/
void Write_tofile()
{
    FILE * fp;
    if((fp=fopen("��Ԫʽ.txt","w"))==NULL)
    {
        cout<<"Failure to open ��Ԫʽ.txt\n";
        exit(0);
    }
    fwrite(Si,sizeof(struct Siyuan),Begin-1,fp);
    fclose(fp);
}
/********************************��������д���ļ�***************/

void Write_file()
{
    FILE * fp;
    if((fp=fopen("������.txt","w"))==NULL)
    {
        cout<<"Failure to open ������.txt\n";
        exit(0);
    }
    fwrite(Goal,sizeof(struct Goal),Begin-1,fp);
    fclose(fp);
}
/****************************����Ŀ�����**********************/
void INITT(int x,string g1,string g2,string g3)
{
    Goal[start].step=x;
    Goal[start].G1=g1;
    Goal[start].G2=g2;
    Goal[start].G3=g3;
    start++;
}
///*************************�ַ���ת��������*******************/
int StrtoNum(string ss)
{
    int num;
    stringstream s1(ss);
    s1>>num;
    return num;
}
/*************************����ת�����ַ���*******************/
string NumtoStr(int x)
{
    stringstream ss;
    ss<<x;
    return ss.str();
}
void cout_G(int i)
{
    cout<<Goal[i].step<<" : "<<Goal[i].G1<<" "<<Goal[i].G2<<" "<<Goal[i].G3<<endl;
}
void Goal_Prog()
{
    cout<<"������:"<<endl;
    for(int i=0;i<Begin;i++)
    {
        switch (Si[i].op[0])
        {
        case 'i':
            INITT(END++,"DW",Si[i].step,"");
            cout_G(start-1);
            break;
        case '=':
            INITT(END++,"MOV",Si[i].step,Si[i].w1);
            cout_G(start-1);
            break;
        case '+':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"ADD","AX",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
            break;
        case '-':
            INITT(END++,"CMP",Si[i].w2,Si[i].w1);
            cout_G(start-1);
            END++;

            INITT(END,"JNC","",NumtoStr(END+3));
            cout_G(start-1);

            INITT(END++,"SBB",Si[i].w2,Si[i].w1);
            cout_G(start-1);

            INITT(END++,"JMP","",NumtoStr(END+2));
            cout_G(start-1);

            INITT(END++,"SUB",Si[i].w2,Si[i].w1);
            cout_G(start-1);
            break;
        case '*':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IMUL","",Si[i].w1);
            cout_G(start-1);

            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
        case '/':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IDIV","",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"AX");
            cout_G(start-1);
            break;
        case '%':
            INITT(END++,"MOV","AX",Si[i].w2);
            cout_G(start-1);
            INITT(END++,"IDIV","",Si[i].w1);
            cout_G(start-1);
            INITT(END++,"MOV",Si[i].step,"DX");
            cout_G(start-1);
            break;
        case '>':
            INITT(END++,"CMP",Si[i].w1,Si[i].w2);
            cout_G(start-1);
            break;
        case 'J':
            INITT(END++,"JC","",NumtoStr(END+StrtoNum(Si[i].step)-i));
            cout_G(start-1);
            break;
        }
    }
}
void function()
{
    char* s="1.txt";
    Read_file(s,getsym);//��ȡ�������
    length=getsym.size();
    getSym();//�������
    s="f1.txt";
    Read_filef1(s);
    Expression();
    Write_tofile();
    Goal_Prog();
    Write_file();
    //cout<<Begin<<endl;
    //cout<<"$$$$$$$$$$$$$4\n";
}
int main()
{
    function();
    return 0;
}

