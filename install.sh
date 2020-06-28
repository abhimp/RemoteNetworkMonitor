#!/usr/bin/env bash

cat > /tmp/remoteMonitor.service <<EOF
[Unit]
Description=Remote network state monitor service.

[Service]
Type=simple
Restart=always
RestartSec=1
ExecStart=/usr/bin/remote_monitor

[Install]
WantedBy=multi-user.target
EOF

try() {
    $@

    if [ $? -ne 0 ]
    then
        exit
    fi
}

try python3.7 ./createHeader.py
try gcc -o remote_monitor serv.c


sudo systemctl stop remoteMonitor
sudo cp remote_monitor /usr/bin/
sudo cp /tmp/remoteMonitor.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl restart remoteMonitor
sudo systemctl enable remoteMonitor
sudo systemctl status remoteMonitor
