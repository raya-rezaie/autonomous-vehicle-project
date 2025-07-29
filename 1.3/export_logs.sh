#!/bin/bash
USER_HOME="/home/h"
EXPORT_DIR="$USER_HOME/research/all_logs_export_$(date +%F_%H-%M-%S)"
mkdir -p "$EXPORT_DIR"

cp -a /var/log "$EXPORT_DIR"/
 
 journalctl > "$EXPORT_DIR/journal_full.txt"

 journalctl -o json > "$EXPORT_DIR/journal_full.json"



echo "All logs exported"