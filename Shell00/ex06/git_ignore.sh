#!/bin/bash
cd $(git rev-parse --show-toplevel)

git ls-files --others --ignored --exclude-standard
