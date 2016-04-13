#!/bin/bash
cd ../../../src/myo_raw/data/ros\ bags
fn=$(ls -t | grep ".bag" | head -n1)
mv -f -- "$fn" "bagTrash"
