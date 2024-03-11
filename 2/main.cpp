#include <iostream>
#include <clocale>


int main()
{
    setlocale(LC_ALL, "Russian");
    
    std::string Scobki;
    getline(std::cin,Scobki);

    int Pravda=1;
    long t_Scobki = size(Scobki);
    
    char* Stak {new char[t_Scobki/2]};
    int Stak_Count = 0;
    
    for(int i=0; i<t_Scobki/2;i++) Stak[i]='0';
    
    if (t_Scobki%2==0)
    {
        if ((Scobki[0]!=')') && (Scobki[0]!=']') && (Scobki[0]!='}'))
        {
            for (int i=0; i<t_Scobki;i++)
            {
                if (Pravda==1)
                {
                    if ((Stak[Stak_Count]=='0') && (i==t_Scobki-1) && (Stak_Count==0) && ((Scobki[i]=='}')||(Scobki[i]==')')||(Scobki[i]==']'))) Pravda=0;
                    
                    else
                    {
                        if ((Scobki[i]=='(')||(Scobki[i]=='{')||(Scobki[i]=='['))
                        {
                            Stak[Stak_Count]=Scobki[i];
                            Stak_Count++;
                        }
                        else
                        {
                            if ((Scobki[i]==')')&&(Stak[Stak_Count-1]=='('))
                            {
                                Stak[Stak_Count-1]='0';
                                Stak_Count--;
                            }
                            else if(Scobki[i]==')') Pravda=0;
                            if ((Scobki[i]==']')&&(Stak[Stak_Count-1]=='['))
                            {
                                Stak[Stak_Count-1]='0';
                                Stak_Count--;
                            }
                            else if(Scobki[i]==']') Pravda=0;
                            if ((Scobki[i]=='}')&&(Stak[Stak_Count-1]=='{'))
                            {
                                Stak[Stak_Count-1]='0';
                                Stak_Count--;
                            }
                            else if(Scobki[i]=='}') Pravda=0;
                        }
                    }
                }
                
            }
            if (Stak_Count!=0) Pravda=0;
        }
        else Pravda=0;
    }
    else Pravda=0;
    
    if (Pravda==1) std::cout << std::endl << "Верно" << std::endl;
    else std::cout << std::endl << "Неверно" << std::endl;
    
    delete [] Stak;
}
