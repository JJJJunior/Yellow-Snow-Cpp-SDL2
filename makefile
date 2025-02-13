# 项目名称（最终生成的可执行文件）
TARGET = my_project.exe

# 编译器
CXX = g++

# 目录设置
SRC_DIR = src
BUILD_DIR = build

# 搜索所有 .cpp 源文件
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# 生成对应的 .o 文件
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# SDL2 及其扩展库的路径（手动指定，不使用 pkg-config）
SDL2_INCLUDE = -Isrc/include
SDL2_LIB = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

# 编译选项
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -Wno-unused-parameter $(SDL2_INCLUDE)

# 目标规则
$(TARGET): $(OBJS)
	$(CXX) $^ -o $@ -Lsrc/lib $(SDL2_LIB)

# 编译规则
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 创建 build 目录（Windows 兼容）
$(BUILD_DIR):
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# 清理
.PHONY: clean
clean:
	if exist $(TARGET) del /F /Q $(TARGET)
	if exist $(BUILD_DIR) rmdir /S /Q $(BUILD_DIR)

# 运行程序
.PHONY: run
run: $(TARGET)
	./$(TARGET)


rebuild: clean run