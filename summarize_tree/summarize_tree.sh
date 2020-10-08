#!/usr/bin/env bash

echo "There were $(find "$1" -type d -print | wc -1) directories"
echo "There were $(find "$1" -type f -print | wc -1) files"
