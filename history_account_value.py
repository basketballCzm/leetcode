import requests
import json

url = "http://api.eosnewyork.io/v1/history/get_actions"

response = requests.post(url, data = json.dumps({"account_name":"gm3denbwguge","pos":0,"offset":396}))

json_response = response.json()["actions"]

sum  = 0.0;
def get_value(str):
	return float(str.split(" ")[0])

for x in json_response:
	if "transfer" == x["action_trace"]["act"]["name"]:
		if "gm3denbwguge" == x["action_trace"]["act"]["data"]["from"]:
			sum = sum - get_value(x["action_trace"]["act"]["data"]["quantity"])
			#print(get_value(x["action_trace"]["act"]["data"]["quantity"]))
		if "gm3denbwguge" == x["action_trace"]["act"]["data"]["to"]:
			sum = sum + get_value(x["action_trace"]["act"]["data"]["quantity"])
			#print(get_value(x["action_trace"]["act"]["data"]["quantity"]))
	else:
		if 0 == len(x["action_trace"]["inline_traces"]):
			continue
		else:
			for y in x["action_trace"]["inline_traces"]:
				# inline_traces has inline_traces
				if ("gm3denbwguge" == y["receipt"]["receiver"]) and ("transfer" == y["act"]["name"]):
					if "gm3denbwguge" == y["act"]["data"]["from"]:
						sum = sum - get_value(y["act"]["data"]["quantity"])
						print(-get_value(y["act"]["data"]["quantity"]))
					if "gm3denbwguge" == y["act"]["data"]["to"]:
						sum = sum + get_value(y["act"]["data"]["quantity"])
						print(-get_value(y["act"]["data"]["quantity"]))


print (sum)
