#!/bin/bash
mkdir -p language-models
aws s3 sync s3://language-models language-models --include "*raw/*"
