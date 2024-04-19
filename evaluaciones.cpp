#include<iostream>
using namespace std;
int opcion,a=0;
int acum=0;
void Inicio();
void Ingreso_Estudiantes();
struct Estudiantes
{
string nombre,apellido;
int cedula,seccion;
double nota,nf;
}o;
struct MateriaP
{
 int modo,exa,cantidad_estudiantes,sec;
 int porcentaje;
}poo;
void Inicio()
{   system("cls");
cout<<"PROGRAMACION ORIENTADA A OBJETOS"<<endl;
	cout<<"\n*Modo de evaluacion*:"<<endl;
	cout<<"\nModo de Evaluacion para el semestre\n1.Acumulativo\n2.Examen Final"<<endl;
	cin>>poo.modo;
	cout<<"\n*Materia*:"<<endl;
    cout<<"Seccion:";
	cin>>poo.sec;
	cout<<"Matricula:";
    cin>>poo.cantidad_estudiantes;
    cout<<"Numero de evaluaciones a realizar:";
    cin>>poo.exa;
}
void estudiantes_datos()
{   o.nombre=" ";
    o.apellido=" ";
    o.cedula=0;
    o.nf=0;
    int entero;
    double decimal;
    o.nf=0;
	int tam=poo.exa+1; 
	Estudiantes Notas[poo.cantidad_estudiantes][tam];
    Estudiantes Lista[poo.cantidad_estudiantes][3];
    int calFinal[poo.cantidad_estudiantes];
    double Def[poo.cantidad_estudiantes];
    MateriaP Valor_Evalua[tam];
    system("cls");
    for(int i=0;i<poo.cantidad_estudiantes;i++)
    {
    	for(int j=0;j<tam;j++)
    	{
    		Notas[i][j].nota=0;
		}
	}
	if(poo.modo==2)
   {
	cout<<"\n70%  ("<<tam-1<<"  evaluaciones)"<<endl;
    do{
	for(int i=0;i<tam-1;i++)
    {
    	cout<<"Indique % para la evaluacion"<<"("<<i+1<<")"<<endl;
    	cin>>Valor_Evalua[i].porcentaje;
    	acum=acum+Valor_Evalua[i].porcentaje;
	}
	if(acum!=70)
	{   system("cls");
		cout<<"Debe modificar los porcentajes ,ya que la suma de ellos es distinta del 70%"<<endl;
		acum=0;
		 cout<<"Cantidad de evaluaciones:"<<poo.exa<<endl;
	}
	}while(acum!=70);
}

cout<<"Presione enter para continuar..."<<endl;
cin.get();cin.get();
system("cls");
if(poo.modo==2)
{ cout<<"****CASO2:Examen final****"<<endl; 
}else
{cout<<"****CASO1:Acumulativo****"<<endl;
}
double caso1=0;
    for(int i=0;i<poo.cantidad_estudiantes;i++)
    {
	 cout<<"\nN:"<<i+1<<endl;
	 cout<<"Cedula de identidad:";
	 cin>>Lista[i][2].cedula;
	  while(Lista[i][2].cedula>99999999||Lista[i][2].cedula<=9999999)
     {
     	cout<<"La cedula no puede contener menos de 8 digitos,tampoco mas de 8"<<endl;
     	cin>>Lista[i][2].cedula;
	 }
     cout<<"Nombre:";
     cin>>Lista[i][0].nombre;
     cout<<"Apellido:";
     cin>>Lista[i][1].apellido;
    
     cout<<"*Ingreso de notas para el estudiante"<<i+1<<" *\n";
     for(int j=0;j<tam-1;j++)
     { 
     	cout<<"Nota:"<<"("<<j+1<<")";
     	if(poo.modo==2)
     	cout<<"("<<Valor_Evalua[j].porcentaje<<"%):";
        cin>>Notas[i][j].nota;
        while(Notas[i][j].nota>10||Notas[i][j].nota<0)
        {cout<<"Rango de notas (0-10),ingrese nuevamente"<<endl;
        if(poo.modo==1)
        cout<<":";
        cin>>Notas[i][j].nota;
        if(poo.modo==1&&j==tam-2)
        cin>>Notas[i][tam-1].nota;
		}
        o.nf=o.nf+((Notas[i][j].nota)*(((double)Valor_Evalua[j].porcentaje)/(double)100));
        caso1=Notas[i][j].nota+caso1;
    }   
    caso1=caso1/(double)(tam-1);
    if(poo.modo==1)
    Def[i]=caso1;
    else
    Def[i]=o.nf;
    if(o.nf>=3.5&&poo.modo==2)
    {cout<<"Previa:"<<o.nf;
	 cout<<"\nFinal (30%):";
	 cin>>Notas[i][tam-1].nota;
	 Def[i]=Def[i]+(Notas[i][tam-1].nota*0.30);
    }
        o.nf=Def[i];
        entero=(int)o.nf;
	    decimal=(double)entero+0.5;
	    if(o.nf>=decimal)
	    calFinal[i]=entero+1;
	    else
	    calFinal[i]=entero;
o.nf=0;
 system("cls");  
 caso1=0; 
}
cout<<"P.O.O."<<endl;
cout<<"Seccion:"<<poo.sec<<endl;
cout<<"Matricula:"<<poo.cantidad_estudiantes<<endl;
cout<<"\nN   |NOMBRE\t\t|APELLIDO\t|CEDULA  ";
if(poo.modo==1)
tam=tam-1;
for(int i=0;i<tam;i++)
{
	cout<<"| Nota"<<i+1;
}
cout<<"| D   | F  |";
cout<<endl;
for(int i=0;i<poo.cantidad_estudiantes;i++)
{
	    cout<<i+1<<"   |";
		cout<<Lista[i][0].nombre<<"\t\t"<<Lista[i][1].apellido<<"\t\t"<<Lista[i][2].cedula<<" |";
			for(int k=0;k<tam;k++)
			{
				cout<<Notas[i][k].nota;
				if(Notas[i][k].nota<10)
				cout<<"     |";
				else
				cout<<"    |";
			}
	cout<<Def[i];
	if(Def[i]<10)
	cout<<"    |";
	else
	cout<<"  |";
	cout<<calFinal[i];
	if(calFinal[i]<10)
	cout<<"   |";
	else 
	cout<<"  |";
	cout<<endl;
}
double promedio=0;
if(poo.modo==2)
{
	cout<<"Porcentajes de las evaluaciones:"<<endl;
	for(int i=0;i<tam-1;i++)
	{
		cout<<"%"<<i+1<<"Evaluacion:"<<Valor_Evalua[i].porcentaje<<endl;
	}
}
cout<<"Promedios de las evaluaciones"<<endl;
for(int i=0;i<tam;i++)
{
	for(int j=0;j<poo.cantidad_estudiantes;j++)
	{
		promedio=Notas[j][i].nota+promedio;
	}
	promedio=promedio/poo.cantidad_estudiantes;
	cout<<"NOTA "<<i+1<<" :"<<promedio<<endl;
	promedio=0;
}
}
int main()
{    Inicio();
     estudiantes_datos();
	cin.get();cin.get();
}
