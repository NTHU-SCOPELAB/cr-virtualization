FROM gcc:15

USER root

COPY socket_server /src/server

RUN chmod +x /src/server

WORKDIR /src

EXPOSE 8888

ENTRYPOINT [ "/src/server" ]

CMD []