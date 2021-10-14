#!/bin/bash

# Use: sh azcli_upload_blob.sh <file path>

ACCOUNT_NAME=videoframesstorage
CONTAINER=frames
FILE=$1 
NAME=$1

source sas_token.sh
#az login
az storage blob upload --account-name $ACCOUNT_NAME --sas-token $SAS --file $FILE --name $NAME --container-name $CONTAINER
