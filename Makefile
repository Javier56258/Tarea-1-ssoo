# Variables
CXX = g++
CXXFLAGS = -std=c++11 -pthread -Wall -Wextra -g
TARGET = Tarea1SO
SOURCES = Tarea1SO.cpp
OBJECTS = Tarea1SO.o

# Compilación
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para generar archivos .o
Tarea1SO.o: Tarea1SO.cpp
	$(CXX) $(CXXFLAGS) -c Tarea1SO.cpp -o Tarea1SO.o

# Limpiar archivos generados
clean:
	rm -f $(TARGET) $(OBJECTS)
