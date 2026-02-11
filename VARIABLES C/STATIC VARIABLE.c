¡Las variables estáticas tienen la propiedad de preservar su valor incluso después de que estén fuera de su alcance! 
Por lo tanto, las variables estáticas conservan su valor anterior en su ámbito anterior y no se inicializan de nuevo 
en el nuevo ámbito. 

static cumple con dos funciones básicas dentro del lenguaje C:


1.Al usarlo sobre variables que están dentro de una función: 
	- permite que el valor de las mismas persista entre llamadas
	- static: modificador para indicar que una variable debe mantener su valor entre llamados de funcion
	
	int INCREMENTAR(void){
		static int x=5;
		x++;
		return x;		
	}
	  
	- Al ejecutar el programa, sucede lo siguiente, ingresa a la funcion INCREMENTAR.
	- Se crea la variable statica "x" y se inicializa con un valor de "5"
	- Luego esta variable se aumenta y retorna el valor de "6"
	- Ahora la 2da y demas veces que se ingresa a la funcion INCREMENTAR, ya no vuelve a inicializar la variable "x" a "5"
	  (es como si la linea "static int x=5;" ya no existiera o se hubiera borrado), y "x" se mantendria con el valor
	  anterior de "6" (ya que el compilador le asigna un espacio de memoria a las variables staticas y no las destruye 
	  como se hace normalmente con las variables comunes dentro de una funcion) luego esta variable se vuelve a aumentar 
	  y retornaria "7" y asi sucesivamente.
	- Ahora la variable statica "x" esta almacenada en un espacio de memoria fijo y puede ser accedida desde cualquier 
	  parte del programa, pero solo puede ser modificada unicamente dentro de la funcion INCREMENTAR.
	


2.Al usarlo sobre funciones o variables de ámbito global, garantiza que dicho elemento (variable o función) solo exista 
  en la unidad de compilación en la que se encuentre declarado.
  
  Cuando una función se declara como estática, tan sólo puede ser invocada desde el fichero en el que está definida. 
  Este mecanismo, por tanto, puede interpretarse como una forma primitiva de restringir el acceso a una función.
  
	- No llevan un prototipo en el .h(de una libreria) como las funciones normales
	- solo existen en el .c y no se puede llamar a esa funcion en al main.c
	- protege funciones, Ejemplo: creas una funcion "static void Sumar(int a, int b)" en el .c(de una libreria)
	  esta funcion solo existe y se podra usar dentro del .c, y no del main.c, de esta manera se limita su uso en 
	  un solo lugar.
	  

