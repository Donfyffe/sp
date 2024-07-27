#pragma once

#include <vector>

#include "selfdrive/ui/sunnypilot/qt/network/sunnylink/services/base_device_service.h"
#include "selfdrive/ui/sunnypilot/qt/network/sunnylink/models/user_model.h"

class UserService : public BaseDeviceService {
  Q_OBJECT

public:
  explicit UserService(QObject* parent = nullptr);
  void load();
  void startPolling();
  [[nodiscard]] QString getCacheKey() const final { return "Users"; };

signals:
  void usersReady(const std::vector<UserModel>&users);

protected:
  void handleResponse(const QString&response, bool success) override;

private:
  QString url = "/users";
};