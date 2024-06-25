# 指定编译器和编译选项  
CC = gcc  

# 指定编译选项为-Wall，用于显示所有警告信息
CFLAGS = -Wall  
  
# 指定目标文件  
TARGET = learning_test  
  
# 指定源文件  
SRCS = learning_test.c  
  
# 指定目标文件和源文件的依赖关系  
$(TARGET): $(SRCS)  
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)  
  
# 清除生成的文件  
clean:  
	rm -f $(TARGET)