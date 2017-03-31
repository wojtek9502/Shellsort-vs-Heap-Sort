


/*
Ogolnie program operuje na dw"ch takich samych tablicach ktore sortuje innym sposobem
shell_array - dla sortowania shella
heap_array - dla sortowania przez kopcowanie

Tablice sa juz wypelnione losowymi liczbami
pozostaje tylko dopisania funkcji sortujacej dla kazdej z tablicy
i zmierzenie czasu przy czym mozna zastosowac funkcje time i liczyc jako uplyw czasu
lub dodawac po kazdym kroku algorytmu wartosc do licznika krok"w i tu musimy zdecydowac
bo robiac i to i to jednoczesnie jeden sposob bedzie opoznial drugi
*/

/*
//--------------------------------------------------------
// Stan projektu
//--------------------------------------------------------
// Zrobione:
//
// Powitajka plus wszystko co zwiazane z wylosowaniem liczb
// z odpowiedniego zakresu (tylko liczb dodatnich),
// zappisaniem ich do tablic i odczytaniem tych tablic
// shell juz jest
// -wymierzenie czasu kazdego sortowania
// -prezentacja wyniku i opis ktore szybsze itp
//-------------------------------------------------------
// Do zrobienia
//
//
// --------------------------------------------------------
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <math.h>

/*
//---------------------------------
// Funkcja do witania
//---------------------------------
*/
void welcome(void)
{

printf("                                Projekt ASiD\n");
printf("             Temat: Por¢wnanie sortowa‰ metodami Shella oraz przez kopcowanie\n");
printf("\n                           Grupa dzieka‰ska: 1D|13A");
printf("\n                           Grupa projektowa: 1\n");
printf("\n                           Skàad osobowy grupy:");
printf("\n                           Kusek Wojciech");
printf("\n                           Kostecki Micha");
printf("\n                           Kowalczyk Marek\n\n");

system("PAUSE");
system("CLS");
}



/*
-----------------------------------------------
Funkcja do wyboru sposobu wypelniania element"w
1= z klawiatury
2= losowo przez funkcje
------------------------------------------------
*/

int choice_function(int choice)
{
    system("CLS");
    printf("Jak chcesz wprowadziÜ elementy do tablicy\n1: Chce wprowadziÜ elementy z klawiatury\n2: Chce wylosowac elementy\nWybieram: ");
    scanf("%d",&choice);
    while((choice<1)||(choice>2))
          {
              printf("Zy wyb¢r. Spr¢buj ponownie: ");
              scanf("%d",&choice);
          }
    return choice;
}



///rozmiar tablicy plus zabezpieczenie. Uzywany w obu sposobach wprowadzania elementow do tablicy
int array_size(int N)
{
    printf("Z ilu element¢w ma si© skàadaÜ tablica (Maksymalnie 259346 element¢w)\nMo´esz wpisaÜ tylko liczby\n");
    scanf("%d",&N);

    while ((N<=0)||(N>259346))
    {
        system("CLS");
        printf("Podaàeò liczb© <=0 lub liczb© nie mieszczac• si© w zakresie.\n(Maksymalnie 259346 element¢w). Mo´esz wpisaÜ tylko liczby\n");
        printf("\nZ ilu element¢w ma si© skàadaÜ tablica: ");
        scanf("%d",&N);
    }
return N;
}


/*
--------------------------------------------
Funkcje gdy chce wprowadzic elementy samodzielnie
rozmiar tablic juz okreslony
------------------------------------------------
*/

void enter_values_by_user(int shell_array[], int heap_array[], int array[], int N)
{
    int i=0;
    int value=0;
    system("CLS");
    for(i=1;i<=N;i++)
    {
       printf("Wprowad´ element nr %d z %d: ",i,N);
       scanf("%d",&value);
       array[i]=value;
       shell_array[i]=value;
       heap_array[i]=value;
    }

}



/*
-------------------------------------------
Funkcje gdy chce wybrac elementy losowo
rozmiar tablic juz okreslony
-------------------------------------------
*/

///wartosc minimalna w losowaniu
int get_min(int min_value)
{
    system("CLS");
    printf("Podaj jako wartoòÜ minimaln• dla losowania liczb© naturaln• wi©ksz• od zera \n");
    scanf("%d",&min_value);
        while(min_value<0)
    {
        system("CLS");
        printf("Podae liczb© <=0. Spr¢buj ponownie\n");
        printf("Podaj jako wartoòÜ minimaln• dla losowania liczb© naturaln• wi©ksz• od zera \n");
        scanf("%d",&min_value);
    }
    return min_value;
}


///wartosc maksymalna w losowaniu
int get_max(int max_value)
{
    system("CLS");
    printf("Podaj jako wartoòÜ maksymaln• dla losowania liczb© naturaln• wi©ksz• od zera \n");
    scanf("%d",&max_value);
    while(max_value<0)
    {
        system("CLS");
        printf("Podae liczb© <=0. Spr¢buj ponownie\n");
        printf("Podaj jako wartoòÜ maksymaln• dla losowania liczb© naturaln• wi©ksz• od zera \n");
        scanf("%d",&max_value);
    }
    return max_value;
}


///wypelnianie tablic losowo
void fill_array(int shell_array[], int heap_array[], int array[], int N, int min_value, int max_value)
{
int i=0;
int substract=max_value-min_value;      ///r¢´nica
srand(time(NULL));
    for(i=1;i<=N;i++)
    {
        shell_array[i]=min_value+rand()%(substract+1); ///+1 inaczej pominie jedna cyfre
        heap_array[i]=shell_array[i];   ///obie tablice maja miec takie same wartosci losowanie bedzie fair itp pierdolenie :D
        array[i]=shell_array[i];
    }

}


/*
---------------------------------------
Funkcje do wypisywania tablic
----------------------------------------
*/


///wypisywanie tablicy shell
void print_shell_array(int shell_array[], int N)
{
    int i=0;

    for(i=1;i<=N;i++)

    {
        printf("%d ",shell_array[i]);
    }
    printf("\n\n");


}


///wypisywanie tablicy kopcowania
void print_heap_array(int heap_array[], int N)
{
    int i=0;
    for(i=1;i<=N;i++)
    {
        printf("%d ",heap_array[i]);
    }
    printf("\n\n");
    system("PAUSE");

}


/*
//----------------------------------
//Funkcje do sortowania
//----------------------------------
*/

int shell_sort(int shell_array[], int N, int shell_steps)
{

    system("CLS");
    printf("Sortuje metod• Shella\n");


  ///i = indeks elementu listy
  ///j - zmienna sterujaca petli
  ///tmp - wybrany ze zbioru element
  ///h - odstep miedzy kolejnymi elementami podzbiorow
    int h,i,j,tmp;

/*
Wyznaczanie odstepu miedzy elementami wg Knutha
*/
  for(h=1; h<=N; h=3*h+1);       ///MUSI BYC ; NA KONCU   ///zaczynamy od odstepu jeden jesli jest nie wiekszy niz N to wyznaczamy go na odstep*3+1
  h = h/9;                      ///odstep dzielimy na 9
  shell_steps++;
  if(h==0)    				///jesli jest rowny 0 to dodajemy i jest 1 gdybby bylo 0 to nie dalo by sie porownyweac elementow
  {
    h++;
    shell_steps++;
  }


//samo sortowanie
  while(h!=0)                    ///odstep miedzy kolejnymi elementami = 0 konczy sortowanie
  {
    for(j=N-h; j>=1; j--)
    {
      tmp = shell_array[j];                     ///zapisujemy liczba z indeksu j
      shell_steps++;

      i= j+h;                                  ///i = liczba z indeksu j+odstep
      shell_steps++;


      while((i<=N) && (tmp>shell_array[i]))  ///jezeli zapisana liczba tmp>i to zamieniamy
      {
        shell_array[i-h] = shell_array[i];     /// i-h to w sumie daje j
        shell_steps++;

        i= i+h;                              ///patrzymy kolejne liczby oddalone od siebie o indeks "h" i zmow sprawdzamy i zamieniamy
        shell_steps++;
      }

      shell_array[i-h] = tmp;
      shell_steps++;

    }
    h = h/3;                            ///liczby oddalone od siebie o indeks h juz posortowane zmniejszamy odstep i od nowa
    shell_steps++;
  }
return shell_steps;
}

///sortowanie polega na zamianie elementu-korzenia z ostatnim elementem-lisciem a nastepnie przywroceniu wàasnosci kopca. Tak w petli az nie bedzie co zzamieniac
///i 	- zmienna licznikowa p©tli pobieraj•cej kolejne elementy z kopca,
///j    - indeks wstawianego elementu
///k    - indeks przodka
///m 	- indeks wi©kszego z dw¢ch element¢w potomnych,

int heap_sort(int heap_array[], int N, int heap_steps)
{
    int i,j,k,tmp,m;
    // Budujemy kopiec

  for(i = 1; i <= N; i++)  ///budowanie zaczynamy od drugiego elementu
  {
    j = i;                     ///zamiana elementu liscia z przodkiem
    heap_steps++;

    k = (j / 2);
    heap_steps++;

    tmp = heap_array[i];
    heap_steps++;
    while((k > 0) && (heap_array[k] < tmp)) ///szukanie miejsca do wstawienia elementu  /// gdyby zmienic "<" na ">" w drugim warunku sortowaloby rosnaco
    {
      heap_array[j] = heap_array[k];   ///przesuwamy przodka na miejsce potomka by zachowaÊ strukture kopca
      heap_steps++;

      j = k;                ///przesuwamy lisc na miejsce zajmowane przedtem przez przodka
      heap_steps++;

      k = j/2;             ///przodek jest teraz dobrze ustawiony
      heap_steps++;
    }
    heap_array[j] = tmp; ///zmienna j wskazuje teraz miejsce gdzie wstawic element i tam go wstawiamy
    heap_steps++;
  }

// Rozbieramy kopiec

  for(i=N; i>1; i--)          ///rozbieranie kopca czuli element przodka zamienia sie z lisciem
    {
    tmp = heap_array[1];
    heap_steps++;

    heap_array[1] = heap_array[i];  ///zamieniamy
    heap_steps++;

    heap_array[i] = tmp;
    heap_steps++;

    j = 1;       heap_steps++;
    k = 2;       heap_steps++;


    ///j -indeks przodka
    ///k - indeks lewego potomka
    ///i - indeks elementu przegladanego
    ///konczy sie gdy indeks j-ty nie posiada potomka



    ///przegladanie od korzenia w dol
        while(k < i)    ///przywracanie struktury kopca
        {
        if((k + 1 < i) && (heap_array[k + 1] > heap_array[k]))   ///jesli indeks prawego potomka jest mniejszy od aktualnie przegladanego potomka && prawy potomek jest wiekszy od lewego (tak jak powinno byc)
            {
            m = k + 1;      ///to zapisujemy go do m
            heap_steps++;
            }
           else
           {
               m = k;     /// jesli prawy mniejszy od prawego to tez zapisujemy
               heap_steps++;
           }

            if(heap_array[m] <= heap_array[j]) break;    /// i tu decyzja jesli to co jest zapisane w m jest <=lewemu potomkowi to kopiec ma dobra strukture i nic nie trzeba robic

            ///ale jesli ma zla (czyli prawy potomek [zapisany w m] mniejszy od lewego)
        tmp = heap_array[j];  ///zamieniamy
        heap_steps++;

        heap_array[j] = heap_array[m];
        heap_steps++;

        heap_array[m] = tmp;
        heap_steps++;   ///koniec zamiany

        j = m;      ///wyznaczamy indeks nowego przodka
        heap_steps++;

        k = j + j;  ///wyznaczamy nowy indeks lewego przodka
        heap_steps++;
        }
  }    ///struktura petli przywrocona mozna rozebrac nastepny element i z kopca w pierwszej petli

return heap_steps;
}


/*
------------------------------------------------
Funkcja wypisuj|ca wyniki sortowan i porownujaca
-------------------------------------------------
*/
void results(int N, double shell_time, double heap_time, int shell_steps, int heap_steps)
{
    system("CLS");
    printf("WYNIKI DZIAùANIA PROGRAMU\n");
    printf("Liczba element¢w do sortowania: %d\n\n",N);
    printf("Sortowanie Shella\nCzas sortowania: %.0lfms\nLiczba krok¢w w algorytmie: %d\n\n",shell_time,shell_steps);
    printf("Sortowanie przez kopcowanie\nCzas sortowania: %.0lfms\nLiczba krok¢w w algorytmie: %d\n\n",heap_time,heap_steps);
    printf("WNIOSKI:\nAlgorytm sortowania przez kopcowanie jest szybszy od sortowania Shella,\njednak liczba krok¢w potrzebnych do posortowania jest wi©ksza (nawet jesli \nliczby sa losowane z duæego zakresu). Pokazuje to, ´e algorytm Shella jest\nalgorytmem wydajniejszym.\n\n");
}


/*
//--------------------------------
// Funkcja main
//--------------------------------
*/
int main(void)
{
    ///wybor sposobu wprowadzania element"w do tablicy
    int choice=0;

    ///liczniki
    int start_prog=clock(), start_sort=0, end_sort=0;

    ///zmienne na przechowanie czasu sortowania
    double shell_time=0, heap_time=0;

    ///do tablicy
    int N=0, min_value=0, max_value=0;

    ///do liczby korokow algorytmow sortowan
    int shell_steps=0, heap_steps=0;


    ///Wywoanie: Ekran tytulowy
    welcome();


    N=array_size(N);
    int shell_array[N];
    int heap_array[N+1];
    int array[N];


    ///sprawdzanie jak chce wprowadzic  1= z klawiatury 2=losowo z funkcji
    choice=choice_function(choice);
    switch(choice)
    {
        case 1:
        {
            enter_values_by_user(shell_array,heap_array,array,N);
        } break;


        case 2:
            {
               min_value=get_min(min_value);                /// element minimalny do losowania
               max_value=get_max(max_value);                /// element maksymalny do losowania

        ///gdy wartosc minimalna liczb z ktorych losujemy jest wieksza od maksymalnej

                while(min_value>max_value)
                {
                system("CLS");
                printf("wartoòÜ minimalna jest wicksza od masymalnej.\nMo´e to powodowaÜ problemy.\nUzupenij wartoci raz jeszcze.\n");
                system("PAUSE");
                min_value=get_min(min_value);
                max_value=get_max(max_value);
                }

                    ///Wywo^anie: uzupelnianie tablic
                fill_array(shell_array,heap_array,array,N,min_value,max_value);

            } break;

    }

    system("CLS");
    printf("Wartoòci zostaày dobrane prawidàowo.\nSortowanie odbywa si© na takiej samej tablicy.\n\nPo wciònicciu klawisza rozpocznie si© sortowanie\nCzas i liczba krok¢w b©d• liczone osobno dla kaædego sortowania. \nGdy oba sie zako‰cz• wyòwietlony zostanie wynik testu algorytm¢w.\n\n");
    system("PAUSE");



    ///TU JU'Ò SAME SORTOWANIA

    ///sortowanie shell
    start_sort=clock();     ///poczatek
            shell_steps=shell_sort(shell_array,N,shell_steps);  ///wywolanie sortowania zwroci ono do zmiennej shell steps liczbe korokow
    end_sort=clock();      ///koniec


    printf("Wypisuje posortowan• tablice\n");
    print_shell_array(shell_array,N);


	///Wyliczanie czasu dla shella
    shell_time = (end_sort-start_sort)-start_prog/CLOCKS_PER_SEC;
    system("PAUSE");


    ///wyzerowanie licznikçw
    start_sort=0;
    end_sort=0;



    ///sortowanie przez kopcowanie
    system("CLS");
    start_sort=clock();     ///poczatek
            heap_steps=heap_sort(heap_array,N,heap_steps);  ///wywolanie sortowania zwroci ono do zmiennej shell steps liczbe korokow
    end_sort=clock();      ///koniec

	printf("Sortuje metod• kopcowania\n");
    printf("Wypisuje posortowan• tablice\n");
    print_heap_array(heap_array,N);

	///wyliczanie czasu dla kopcowania
    heap_time= (end_sort-start_sort)-start_prog/CLOCKS_PER_SEC;

	///przeslanie wynikow do funkcji ktora je wywietli
    results(N,shell_time,heap_time,shell_steps,heap_steps);
    return 0;
}
