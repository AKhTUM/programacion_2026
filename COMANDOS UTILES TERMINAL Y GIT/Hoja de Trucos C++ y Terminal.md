***Hoja de Trucos: C++ y Terminal
Compilación (g++)***



**<i>~~"PORQUE SE ME OLVIDA LOS COMANDOS XDDD"~~</i>**



*Compilar un solo archivo:*



* Bash

g++ tu\_archivo.cpp -o nombre\_programa.exe

Compilar un proyecto con múltiples archivos (ej. clases separadas):



* Bash

g++ main.cpp espada.cpp solar.cpp -o juego.exe

(O el truco para compilar todos los .cpp de la carpeta al mismo tiempo):



* Bash

g++ \*.cpp -o programa.exe

Ejecución



*En la terminal de Windows:*



**Bash**

.\\nombre\_programa.exe

En la terminal de Mac / Linux (por si el profe usa otro sistema):



**Bash**

./nombre\_programa

🌳 Hoja de Trucos: Git y GitHub

El ciclo de vida diario (Guardar y Subir)



*Ver qué archivos han sido modificados:*



**Bash**

git status

Preparar todos los archivos modificados para guardarlos:



**Bash**

git add .

Crear el "paquete" con un mensaje descriptivo:



**Bash**

git commit -m "Agregue la clase base y modifique el main"

Subir el paquete a GitHub:



**Bash**

git push

Manejo de Ramas (Branches)



*Crear una rama nueva y cambiarte a ella inmediatamente:*



**Bash**

git switch -c nombre-nueva-rama

Cambiar de una rama a otra (ej. regresar al main):



**Bash**

git switch main

Descargar la información más reciente de GitHub:



**Bash**

git fetch

Actualizar tu rama actual con lo que hay en la nube:



**Bash**

git pull

Fusión (Merge)



Cámbiate a la rama que va a recibir los cambios (git switch main).



*Ejecuta la fusión:*



**Bash**

git merge nombre-de-la-rama-a-fusionar

