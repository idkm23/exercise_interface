#!/bin/bash
cd ../../../src/myo_raw/data
fn=$(ls -t | grep ".bag" | head -n1)
mv -f -- "$fn" "bagTrash"
