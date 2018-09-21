import socket
import yaml
import sys


def load_settings(file):
    with open(file, 'r') as f:
        data = yaml.safe_load(f)
    return data


def send_payload(address, port, payload):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((address, int(port)))
    sock.listen(5)
    sock.send(payload.encode())
    sock.close()
    return


def build_payload(payload):
    _payload = ''
    default_delay = 10
    for item in payload.get('payload'):
        for key, value in item.items():
            if key == 'press_key':
                _payload += f"{str(value)}.{default_delay},"
            elif key == 'delay':
                _payload = _payload.removesuffix(f'{default_delay},')
                _payload += f"{str(value)},"
            elif key == 'type':
                for c in value:
                    char_to_dec = ord(c)
                    _payload += f"{str(char_to_dec)}.{default_delay},"
    # print('payload --> ', _payload)
    print('Payload Length -->', len(_payload.encode('utf-8')))
    return _payload


def main():
    args = sys.argv
    settings = load_settings(args[1])
    payload = settings.get(args[2])
    encoded_payload = build_payload(payload)
    send_payload(
        settings.get('Server_Settings').get('address'),
        settings.get('Server_Settings').get('port'),
        encoded_payload
    )
    return


if __name__ == '__main__':
    main()
