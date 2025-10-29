# 文件移动指南

## 目标
将 `llfc_chat` 根目录下的源文件移动到 `client/` 子目录，并通过 git 推送到远程仓库。

## 方法1：使用批处理脚本（推荐）

1. **运行移动脚本**
   ```bash
   cd llfc_chat
   move_files.bat
   ```

2. **检查移动结果**
   ```bash
   git status
   ```

3. **提交更改**
   ```bash
   git add -A
   git commit -m "Move source files to client/ subdirectory"
   ```

4. **推送到远程仓库**
   ```bash
   git push origin main
   # 或
   git push origin master
   ```

## 方法2：手动移动（精确控制）

### 步骤1：移动单个文件（如果已被 git 跟踪）
```bash
cd llfc_chat

# 使用 git mv（保留文件历史）
git mv main.cpp client/
git mv login.cpp client/
git mv login.h client/
git mv login.ui client/
# ... 其他文件
```

### 步骤2：移动未被跟踪的文件
```bash
# 普通移动
move *.cpp client/
move *.h client/
move *.ui client/
move *.qrc client/
move *.qss client/
move *.pro client/
move *.ico client/
move config.ini client/

# 移动目录
move image client/
```

### 步骤3：添加到 git（如果是新文件）
```bash
git add client/
git status
```

### 步骤4：提交并推送
```bash
git commit -m "Move source files to client/ subdirectory"
git push origin main
```

## 注意事项

1. **检查冲突**：如果 `client/` 目录下已有同名文件，需要先处理冲突
2. **保留历史**：使用 `git mv` 而不是 `move`，可以保留文件的 git 历史
3. **更新路径**：如果 `.pro` 文件中有相对路径引用，可能需要更新
4. **备份**：移动前建议先备份或创建一个分支
   ```bash
   git checkout -b move-to-client
   ```

## 文件列表（需要移动的文件）

### 源文件
- `*.cpp` (main.cpp, login.cpp, register.cpp, 等)
- `*.h` (login.h, register.h, 等)
- `*.ui` (login.ui, register.ui, 等)

### 项目文件
- `*.pro` (llfc_chat.pro)
- `*.qrc` (res.qrc)
- `*.qss` (styleSheet.qss)
- `*.ico` (image.ico)

### 配置文件
- `config.ini`

### 资源目录
- `image/` (包含所有图片文件)

### 不需要移动的文件
- `*.pro.user*` (Qt Creator 用户配置文件)
- `build/` (编译输出目录)
- `client/` (目标目录本身)

