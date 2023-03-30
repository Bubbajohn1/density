set echo on

echo "building everything..."

pushd engine
sorce build.sh
popd

ERRORLEVEL = $?
if [ $ERRORLEVEL -ne 0 ]
then
echo "error:"$ERRORLEVEL && exit
fi

pushd testbed
sorce build.sh
popd
ERRORLEVEL = $?
if [ $ERRORLEVEL -ne 0 ]
then
echo "error:"$ERRORLEVEL && exit
fi

echo "build was sucessful"