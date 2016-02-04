##
## sighup.sh
## Victor Hugo Erminpour
#!/bin/bash -x

##
## $> kill -HUP $(pid)

configFile=$(pwd)/config
read_config()
{
    echo "SIGHUP signal received."
    test -r "$configFile" && source "$configFile";
}

read_config
trap 'read_config' SIGHUP

echo "Waiting for SIGHUP... (pid = $$)"
while true; 
do
    ## Note that the signal is "generated"
    ## and is in the "pending" state until
    ## the sleep call returns and the signal
    ## is "delivered".
    sleep 5
    #sleep 5 & wait $!
done

