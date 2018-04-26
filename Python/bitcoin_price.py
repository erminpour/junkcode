#!/usr/bin/python3
import requests

BITCOIN_URL = 'https://api.coinmarketcap.com/v1/ticker/bitcoin/'

def get_bitcoin_price():
    response = requests.get(BITCOIN_URL)
    response_json = response.json()
    # Convert the price to a floating point number
    return float(response_json[0]['price_usd'])

def main():
    price = get_bitcoin_price()
    print ('${:,.2f}'.format(price))

if __name__ == "__main__":
    main()
