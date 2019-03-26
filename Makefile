include Makefile.config
.PHONY: all
all: simple
simple:
	g++ $(FLAGS) $(INCLUDE) -c src/dense_flow_gpu.cc
	g++ $(FLAGS) $(INCLUDE) -c src/toolbox.cc
	g++ -o $(OUT)/denseFlow_gpu dense_flow_gpu.o toolbox.o $(LIB) -lopencv_core -lopencv_cudaoptflow -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_videoio
	rm *.o