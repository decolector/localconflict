localconflict
=============

mod de quake3 que postea noticias en la web sobre los eventos del juego.Local Conflict
==============

Local Conflict o Conflicto local es un sistema de seguimiento de ciertos
eventos ocurridos durante un juego de quake3. Los eventos violentos, como
muertes, son utililzados para crear un flujo de noticias en la web, que queda
registrado en un sitio y una red social como twitter.

El trabajo se basa en una version de quake3 modificada para enviar mensajes de
osc ( q3osc ). Estos mensajes son capturados y procesados por un programa que
genera la información y crea un flujo noticioso, albergado en una aplicacion en
la red. 

http://martinez-zea.info/wiki/index.php/LocalConflict/LocalConflict


Instalacion:

ARCHLINUX

Dependencias: openarena, libsdl, libsdl-dev, libopenal, libopenal-dev

La estructura del codigo esta diseniada para residir en el directorio apps de
openframewoks 

1. instalar openarena

2.bajar openframeworks, descomprimir y descender al directorio apps

3. bajar el codigo del repo

4. abrir el workspace en reporterOf71

5. Verificar que esten incluidas las librerias y dependencias (ofxOsc,
ofxXmlSettings y ofxDirlList).  Tener en cuenta incluir la
libreria ofxDirList que se encuentra en src/ y no en addons

6. Compilar

7.compilar q3osc usando el makefile que se encuentra en el directorio q3osc.

    make

    cd build/release-linux-i386

8.si el directorio ccrma existe eliminarlo

    rm ccrma

y

    mv baseq3 ccrma

9.copiar los archivos de /usr/share/openarena/baseoa en el directorio ccrma

10. crear un directorio screenshots en el directorio .openarena/ccrma en el
home, donde se guardaran las imagenes tomadas en el juego

    mkdir ~/.openarena/ccrma/screenshots

11. Editar el archivo de configuracion del reporter
reporterOf71/bin/data/localConflict_settings.xml y cambiar el valor de
<screenshot_path> por el path del directorio recien creado

12. Correr el reporter 



13.correr el juego

    ./ioquake3.i386 +set sv_pure 0 +set fs_game ccrma +set vm_ui 0 +set vm_cgame 0
+set vm_game 0

o usar el script start_conflict.sh



