#include <Arduino.h>

void setup() {
  // 初始化序列通訊，速率設為 115200
  Serial.begin(115200);
  while (!Serial) {
    ; // 等待序列埠連接
  }
  Serial.println("--- 系統啟動成功 ---");
  Serial.println("這是一個連線測試程式。");
  Serial.println("如果你看到這行字，代表你的 Baud Rate 設定正確！");
}

void loop() {
  // 每秒輸出一當前運行秒數
  unsigned long seconds = millis() / 1000;
  Serial.print("系統運行時間: ");
  Serial.print(seconds);
  Serial.println(" 秒");
  
  delay(1000);
}
