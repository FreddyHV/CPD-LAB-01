# Análisis y Comparación de Algoritmos de Multiplicación de Matrices

Este proyecto implementa y compara diferentes algoritmos de multiplicación de matrices en C++, evaluando su desempeño y el uso de la memoria caché. Incluye una implementación clásica con tres bucles anidados y una versión optimizada por bloques con seis bucles anidados. El análisis se complementa con herramientas como Valgrind y KCachegrind para obtener métricas precisas sobre el uso de la memoria.

## Contenido

- [Descripción](#descripción)
- [Algoritmos Implementados](#algoritmos-implementados)
  - [Multiplicación de Matrices Clásica](#multiplicación-de-matrices-clásica)
  - [Multiplicación de Matrices por Bloques](#multiplicación-de-matrices-por-bloques)
- [Análisis del Movimiento de Datos y Caché](#análisis-del-movimiento-de-datos-y-caché)
- [Herramientas de Análisis](#herramientas-de-análisis)


## Descripción

El propósito de este proyecto es estudiar y optimizar el rendimiento de los algoritmos de multiplicación de matrices mediante el uso de técnicas de optimización de caché y algoritmos por bloques. Se investigan las diferencias en cuanto a eficiencia y movimiento de datos entre memoria principal y memoria caché.

## Algoritmos Implementados

### Multiplicación de Matrices Clásica
El algoritmo clásico usa tres bucles anidados para realizar la multiplicación de matrices, con una complejidad de $O(n^3)$.

### Multiplicación de Matrices por Bloques
La versión por bloques mejora el uso de la caché dividiendo las matrices en submatrices más pequeñas y optimizando el acceso a la memoria.
## Análisis del Movimiento de Datos y Caché

Se ejecutan ambos algoritmos paso a paso para analizar cómo los datos se mueven entre la memoria principal y la memoria caché. El algoritmo por bloques demuestra un mejor aprovechamiento de la caché, lo que se traduce en un rendimiento superior, especialmente para matrices grandes.

### Complejidad Algorítmica

- **Multiplicación Clásica**: $O(n^3)$
- **Multiplicación por Bloques**: $O(n^3)$ (misma complejidad teórica, pero optimizada en la práctica debido a la mejor gestión de la caché).

## Herramientas de Análisis

Para analizar el movimiento de datos y el rendimiento de los algoritmos, se utilizaron las siguientes herramientas:

- **Valgrind**: Herramienta para monitorear el uso de la memoria y los fallos de caché.
  - Comando: 
    ```bash
    valgrind --tool=cachegrind ./multiplicacion_matrices
    ```

- **KCachegrind**: Interfaz gráfica para analizar los datos generados por Valgrind y visualizar los fallos de caché. Permite identificar con mayor precisión los cuellos de botella y las áreas del código que no están aprovechando correctamente la jerarquía de memoria.

  - Para abrir los resultados en KCachegrind:
    ```bash
    kcachegrind cachegrind.out.xxxxx
    ```

