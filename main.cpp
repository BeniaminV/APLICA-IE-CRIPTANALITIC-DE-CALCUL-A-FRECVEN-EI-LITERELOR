#include <iostream>
#include <fstream>
#include <cstring>
#include <ctype.h>
#include <stdlib.h>
#include <bitset>
#include <algorithm>

using namespace std;

//The prototype of all functions
void Display();
void DiplayTool();
void Frequency_Counts();
void Convert_From_String_To_Bits();
void Convert_From_String_To_ASCII_Decimal();
void Convert_From_String_To_Hex();
void Caesar_Cipher1();
void Caesar_Cipher2();

int main()
{
    int chose;
    int chose1;

    cout<<"                 Menu"<<endl;
    cout<<endl;
    cout<<"  1.Frequency Counts Function"<<endl;
    cout<<"  2.Application Tools"<<endl;
    cout<<endl;

    cout<<"Chose: ";cin>>chose;
    cout<<endl;

    switch(chose)
    {
        case 1:
            {
                Frequency_Counts();
            }break;
        case 2:
            {
                DiplayTool();
                cout<<endl;
                cout<<"Chose: ";cin>>chose1;
                cout<<endl;

                switch(chose1)
                {
                    case 1:
                        {
                            Convert_From_String_To_ASCII_Decimal();
                        }break;
                    case 2:
                        {
                            Convert_From_String_To_Bits();
                        }break;
                    case 3:
                        {
                            Convert_From_String_To_Hex();
                        }break;
                    case 4:
                        {
                            Caesar_Cipher1();
                        }break;
                    case 5:
                        {
                            Caesar_Cipher2();
                        }break;
                }
            }break;
    }
    return 0;
}

//The menu of the main application
void diplay()
{
    cout<<"1.Frequency counts"<<endl;
}

//The menu for all tools
void DiplayTool()
{
    cout<<"  1.Convert String to ASCII(Decimal)"<<endl;
    cout<<"  2.Convert String to Bit"<<endl;
    cout<<"  3.Convert String to Hex"<<endl;
    cout<<"  4.Caesar Cipher(encrypt)"<<endl;
    cout<<"  5.Caesar Cipher(decrypt)"<<endl;
}

void Frequency_Counts()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];

    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;

    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;

    ifstream ReadFile0(File_Name_Location);
    ofstream WriteFile0(File_Name_Location_Save);

    int vec[127],countt=0,k=0;
    char tmp;
    float x4,x3=100.0;

    if(ReadFile0.is_open())
    {
        //first step is to initialization the vec with value zero
        for(int i=0;i<127;i++)
        {
            vec[i]=0;
        }

        //reading the file till the end
        while(!ReadFile0.eof())
        {
            tmp=ReadFile0.get();
            vec[tmp]++;
        }

        for(int j=0;j<127;j++)
        {
            k=k+vec[j];
        }
        for(int i=0;i<127;i++)
        {
            if(vec[i]!=0)
            {
                x4=(vec[i]*x3)/k;
                WriteFile0<<"#"<<countt<<"symbol["<<i<<"]="<<vec[i]<<" frequency is "<<x4<<" %"<<endl;
                countt++;
            }
            else
                continue;
        }
    }
    else
    {
        cout<<"the file can't be opened"<<endl;
    }
}

void Convert_From_String_To_ASCII_Decimal()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];
    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;
    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;
    ifstream ReadFile1(File_Name_Location);
    ofstream WriteFile1(File_Name_Location_Save);
    int k=0;
    char tmp;
    if(ReadFile1.is_open())
    {
        while(!ReadFile1.eof())
        {
            tmp=ReadFile1.get();
            //to know how many letters are in the file i use a index "k"
            //k=k+1;
            //WriteFile1<<int(tmp)<<" ";
            WriteFile1<<int(tmp);
        }
    }
    else
    {
        cout<<"the file can't be opened"<<endl;
    }
}

void Convert_From_String_To_Bits()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];

    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;

    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;

    ifstream ReadFile2(File_Name_Location);
    ofstream WriteFile2(File_Name_Location_Save);

    char tmp2;
    int k=0;

    if(ReadFile2.is_open())
    {
         while(!ReadFile2.eof())
         {
            tmp2=ReadFile2.get();
            k=k+1;
            //WriteFile2<<bitset<8>(tmp2)<<" ";
            WriteFile2<<bitset<8>(tmp2);
         }
    }
    else
    {
        cout<<"the file can't be opened"<<endl;
    }
}

void Convert_From_String_To_Hex()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];

    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;

    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;

    ifstream ReadFile3(File_Name_Location);
    ofstream WriteFile3(File_Name_Location_Save);

    int k=0;
    char tmp3;

    if(ReadFile3.is_open())
    {
         while(!ReadFile3.eof())
         {
             tmp3=ReadFile3.get();
             k=k+1;
             //WriteFile3<<hex<<(int)tmp3<<" ";
             WriteFile3<<hex<<(int)tmp3;
         }
    }
    else
    {
        cout<<"the file can't be opened"<<endl;
    }
}

void Caesar_Cipher1()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];

    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;

    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;

    ifstream ReadFile4(File_Name_Location);
    ofstream WriteFile4(File_Name_Location_Save);

	int key,k=0,count=0,length,count_letter=0;
	char vector_text[99999];

	cout<<"Write a number for shifting"<<endl;
	cout<<"Key=";cin>>key;

	while(!ReadFile4.eof())
    {
        vector_text[count_letter]=ReadFile4.get();
        count_letter++;
        k=k+1;
    }

    //check if the text is write it in memory
    /*for(int i=0;i<k;i++)
    {
        cout<<vector_text[i];
    }*/

    for(count=0;count<k;count++)
    {
        if(isalpha(vector_text[count]))
        {
            for(int i=0;i<key;i++)
            {
                vector_text[count]=tolower(vector_text[count]);
                if(vector_text[count]=='z')
                    vector_text[count]='a';
                else
                    vector_text[count]++;
            }
        }
    }
    for(int t=0;t<k;t++)
    {
        WriteFile4<<vector_text[t];
    }
}
void Caesar_Cipher2()
{
    //declare the of values for select the file from computer
    char File_Name_Location[255];
    char File_Name_Location_Save[255];

    //here you can write the path for your file
    cout<<"Enter the path of your file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location;

    //in this part of the application you can write the location of the file
    cout<<"Enter the path where you want to save the file"<<endl;
    cout<<"Location: ";cin>>File_Name_Location_Save;

    ifstream ReadFile4(File_Name_Location);
    ofstream WriteFile4(File_Name_Location_Save);

	int key,k=0,count=0,length,count_letter=0;
	char vector_text[99999];

	cout<<"Write a number for shifting"<<endl;
	cout<<"Key=";cin>>key;

	while(!ReadFile4.eof())
    {
        vector_text[count_letter]=ReadFile4.get();
        count_letter++;
        k=k+1;
    }

    //check if the text is write it in memory
    /*for(int i=0;i<k;i++)
    {
        cout<<vector_text[i];
    }*/

    for(count=0;count<k;count++)
    {
        if(isalpha(vector_text[count]))
        {
            for(int i=0;i<key;i++)
            {
                vector_text[count]=tolower(vector_text[count]);
                if(vector_text[count]=='a')
                    vector_text[count]='z';
                else
                    vector_text[count]--;
            }
        }
    }
    for(int t=0;t<k;t++)
    {
        WriteFile4<<vector_text[t];
    }
}
