// Link the production disabled backend without NimBLE, Preferences or fake_ble.
#include "BleKeyboardHost.h"

#include <cassert>
#include <cstdio>

int main() {
  auto& host = freeink::BleKeyboardHost::getInstance();
  assert(!host.begin("disabled"));
  assert(!host.isRunning());
  assert(!host.isStopping());
  assert(!host.connect("AA:BB:CC:DD:EE:01"));
  assert(!host.armSelectedPeerReconnect("AA:BB:CC:DD:EE:01"));
  host.poll();
  host.startScan(100);
  host.stopScan();
  host.disconnect();
  freeink::KeyEvent key;
  freeink::RawButtonEvent raw;
  assert(!host.popKey(key));
  assert(!host.popRawButton(raw));
  assert(host.end());
  assert(host.end());
  std::puts("BLE OFF compile/link/runtime contract PASS");
}
