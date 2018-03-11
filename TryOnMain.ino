#include <LiquidCrystal.h>
LiquidCrystal screen(12, 11, 5, 4, 3, 2);
long i = 0;

void setup()
{
    screen.begin(16,2);
    screen.print(i);
}

void loop()
{
    String iStr = String(i);
    int iStrLen = iStr.length();
    
    int j = i + 1;
    String jStr = String(j);
    int jStrLen = jStr.length();
    if(jStrLen > iStrLen)
    {
        screen.clear();
        screen.print(j);
    }
    else
    {
        for(int l = 0; l < jStr.length(); l++)   
            if(jStr[l] != iStr[l])
            {
                screen.setCursor(l, 0);
                screen.print(jStr[l]);
            }
    }
    i++;
    //screen.clear();
      //  screen.print(i);
        //i++;
//    screen.setCursor(0,1); //on passe à la ligne suivante
//    screen.print("OPENCLASSROOMS");
}
