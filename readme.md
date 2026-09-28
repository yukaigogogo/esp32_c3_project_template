# ESP32-C3 工程模板

基于 ESP-IDF 构建的 ESP32-C3 基础工程模板，适用于各类 ESP32-C3 开发板与自定义硬件方案。

## 1. 工程说明
- **芯片型号**: ESP32-C3 (RISC-V 32-bit 单核)
- **开发框架**: ESP-IDF v6.1
- **代码规范**: Allman 风格
- **文件编码**: UTF-8
- **作者**: yukai

## 2. 硬件引脚配置
- **LED 引脚**: GPIO 8 (可通过 `main/main.c` 宏定义 `LED_GPIO` 自定义修改)

## 3. 快速上手

### 编译工程
```bash
idf.py build
```

### 烧录固件
```bash
idf.py -p COM5 flash
```

### 查看日志
```bash
idf.py -p COM5 monitor
```

## 4. 更新日志 (Changelog)

### [1.0.0] - 2026-09-28
#### 新增
- 初始化 ESP32-C3 基础工程模板。
- 实现基于 FreeRTOS 任务的 LED 循环闪烁及日志输出功能。
- 添加 VS Code 配置文件（包含 OpenOCD JTAG 调试及 Clangd 配置）。
- 配置统一 UTF-8 编码标准与 Allman 规范代码结构。
