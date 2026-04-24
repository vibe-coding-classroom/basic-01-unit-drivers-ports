# Unit: Drivers & Ports (驅動程式與通訊埠)

這是硬體開發的第一站：**連線穩定度測試**。在這個單元中，你將學會如何識別硬體埠號、處理波特率 (Baud Rate) 不匹配導致的亂碼，以及使用 Loopback 測試來排除硬體故障。

## 🎯 學習目標
1. 正確安裝並識別 USB-to-Serial 驅動程式。
2. 了解序列通訊中波特率 (Baud Rate) 同步的重要性。
3. 掌握 Loopback (環回測試) 方法，獨立診斷通聯故障。

## 🛠 任務清單

### 任務 1：環境通聯與偵錯 (Driver & Hardware Debugging)
*   **步驟**：
    1. 將開發板連接至電腦。
    2. 在裝置管理員 (Windows) 或終端機 (Mac/Linux: `ls /dev/tty.*`) 中找到對應的埠號。
    3. 確認橋接晶片型號 (CP2102, CH340 等)。
*   **驗證**：在 `docs/Diagnostic.md` 中記錄你的埠號與晶片型號。

### 任務 2：亂碼解密實驗 (Baud Rate Synchronization Lab)
*   **步驟**：
    1. 使用 PlatformIO 開啟專案並燒錄程式。
    2. 開啟序列監視器 (Serial Monitor)。
    3. 你應該會看到亂碼，因為 `platformio.ini` 中的 `monitor_speed` 被故意設為 `9600`，而程式碼使用的是 `115200`。
    4. 將 `platformio.ini` 中的 `monitor_speed` 修正為 `115200`。
*   **驗證**：修正後截圖清晰的輸出畫面，存為 `assets/serial_ok.png`。

### 任務 3：Loopback 自我對話測試 (Hardware Loopback Test)
*   **步驟**：
    1. 使用杜邦線將板子上的 `TX` 與 `RX` 引腳直接短路。
    2. 開啟序列監視器。
    3. 輸入文字並發送，觀察是否有「回音」顯示在螢幕上。
*   **驗證**：在 `docs/Diagnostic.md` 中記錄測試結果與結論。

## 📁 專案結構
```text
.
├── platformio.ini       # 核心：請在此修正速率設定 (115200)
├── src/main.cpp         # 測試：每秒發送一次信號的基礎程式
├── docs/Diagnostic.md   # 報告：填寫你的診斷過程與結果
├── assets/              # 存放截圖的目錄
└── README.md            # 本說明文件
```

---
> [!TIP]
> 好的工程師，是能透過隔離測試看清資料在透明管道中流動的人。
