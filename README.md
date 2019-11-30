# INF-390 TP2 Submarino

- 92538 - Róger Vieira Batista
- 92559 - Bruno Ferreira Coelho

### Modelos e fontes de consulta

- Modelos
    - https://free3d.com/3d-model/shark-74434.html
    - https://free3d.com/3d-model/tree-coral-v2--625204.html
    - https://free3d.com/3d-model/rms-titanic-34424.html
    - https://free3d.com/3d-model/medieval-boat-50335.html
    - https://free3d.com/3d-model/submarine-v4--863722.html
    - https://free3d.com/3d-model/aquarium-deep-sea-diver-v1--436500.html
    - https://free3d.com/3d-model/box-car-v1--508154.html
    - https://free3d.com/3d-model/-horse-v01--801409.html
    - https://free3d.com/3d-model/rocks--43124.html

- Documentação
    - https://www.khronos.org

- Duvidas gerais
    - https://www.youtube.com/watch?v=P6pJHrA9Avs
    - https://stackoverflow.com/questions/2571402/how-to-use-glortho-in-opengl
    - https://stackoverflow.com/questions/17725670/why-does-gl-shininess-have-a-maximum-value-of-128-0-instead-of-1-0
    - https://stackoverflow.com/questions/31911259/basic-usage-of-mtl-in-opengl
    - https://en.wikipedia.org/wiki/Wavefront_.obj_file
    - https://stackoverflow.com/questions/36964747/ke-attribute-in-mtl-files
    - http://paulbourke.net/dataformats/mtl/
    - https://www.tapatalk.com/groups/nendowingsmirai/wavefront-mtl-file-format-info-t1723.html

- Este link foi consultado para a construção do menu de ajuda. O código altera a projeção dentro de pushMatrix e popMatrix para utilizar coordenadas 2D e depois retorna para a configuração normal para desenhar os objetiso 3D.
    - https://stackoverflow.com/questions/5467218/opengl-2d-hud-over-3d

### Informações adicionais

- O submarino pode ser rotacionado nos três eixos, a rotação em x e z foi colocada para dar mais suavidade ao modelo, para tal foram usadas as teclas 8/2 e 4/6 respectivamente.
- Um objeto guarda informação de dois vetores, o normal q representa o plano do objeto e o diretor com a direção. Com isso, ao apertar a tecla w, o submarino ganha velocidade linear, se delocando para onde o vetor direcional aponta, assim, podendo navegar nas 3 dimensões com suavidade.
- Foi adicionada uma "inércia" em todos os movimentos, conforme uma tecla se mantêm pressionada a velocidade que ele modifica vai convergindo ao valor esperado, ao soltar ela vai decaindo ate chegar a zero, isto da a sensação de inércia do submarino.
- A câmera acompanha o submarino de forma fixa na visão externa, porem na visão interna, ela fica "presa" ao submarino, sendo influenciada pelas rotações aplicadas a ele, isto da a sensação de estar dentro do submarino.
- O arquivo map.txt descreve a localização de cada objeto no oceano.
