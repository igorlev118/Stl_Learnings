// Copyright 2010-2015 Spraylight GmbH

#ifndef __MURL_I_URL_REQUEST_H__
#define __MURL_I_URL_REQUEST_H__

#include "murl_data.h"
#include "murl_map.h"
#include "murl_string.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IUrlRequest
     * @brief The url request interface.
     * The IUrlRequest object can be created by the IWebControl object.
     *
     * After creation, custom HTTP headers can be set for the URL request
     * by calling SetHeaders() with a given string/string map of key/value
     * pairs that define the actual headers. To unset the currently defined
     * headers, ClearHeaders() can be called.
     * To query the current map of headers defined, call GetHeaders().
     *
     * To initiate the actual request, either SendGet() or SendPost() must
     * be called (for each of the available HTTP request types GET and POST,
     * respectively), with a given URL string and an optional timeout value
     * in seconds.
     * SendPost() additionally takes two other parameters: A data object
     * containing the POST data to be sent, and a string defining the content
     * type (e.g. "application/x-www-form-urlencoded"). Note that if the
     * "Content-Type" header was previously defined using SetHeaders(),
     * it is overwritten by the value given with SendPost().
     *
     * After the request was initiated, its current status can be queried
     * in the current logic tick by checking IsPending(), WasFinished() and
     * WasRejected(). Additionally, the current number of received response
     * bytes can be checked via GetCurrentDataSize().
     *
     * As long as IsPending() returns true, the application should keep running
     * and checking both WasFinished() and WasRejected() for every subsequent
     * logic tick. As soon as one of those two methods returns true, the
     * request is done and appropriate action can be taken.
     *
     * If WasRejected() returns true, this indicates that the request failed
     * without ever being able to communicate with the server at the given URL,
     * e.g. when the network is down or when trying to connect to an unknown
     * host.
     *
     * If WasFinished() returns true, this indicates that the system did
     * actually communicate with the given server. To verify that the request
     * was in fact successful, the HTTP response code should be checked by
     * calling GetResponseStatusCode().
     * The value returned by this method is the actual response code sent from
     * the server; see the website https://tools.ietf.org/html/rfc7231 for a
     * list of standardized codes.
     * Codes in the range from 200 to 299 usually indicate success. If any
     * other code was received, the application should react accordingly.
     *
     * Any response data that was sent from the server can be queried via
     * GetResponseData(). In case of success, the data usually contains the
     * requested payload. In other cases, e.g. a 404 (not found) error, the
     * data may contain a simple verbatim description, an actually viewable
     * HTML page describing the error, any other data or simply no data at all.
     * If no data was sent, this method returns an empty data object.
     *
     * The actual set of HTTP response headers can be queried by calling
     * GetResponseHeaders(), which returns a string/string map of header
     * key/value pairs.
     *
     * When a URL request is finally done (either rejected or finished),
     * it can be reused by simply calling SendGet() or SendPost() again,
     * with optionally setting different headers beforehand.
     *
     * Finally, when the received response data is not needed anymore, the
     * method ReleaseData() can be called to release the internal data buffer
     * without destroying the actual URL request object, to save memory.
     */
    class IUrlRequest
    {
    public:
        /**
         * @brief Define custom HTTP headers for the request.
         * This method can be used to define any number of custom HTTP headers
         * sent with the URL request, given as a map containing string key/value
         * pairs for the header names and values, respectively.
         * Note: When using a POST request, the given headers should not include
         * the "Content-Type" and "Content-Length" headers, as they are automatically
         * added during SendPost().
         * @param headers The map of header key/value pairs.
         * @return true if successful.
         */
        virtual Bool SetHeaders(const Map<String, String>& headers) = 0;
        /**
         * @brief Clear any custom HTTP headers for the request.
         * @return true if successful.
         */
        virtual Bool ClearHeaders() = 0;

        /**
         * @brief Send a URL request with http method GET.
         * When posting a URL request the IsPending() state is true.
         * If the URL request was successful the WasFinished() state is true
         * and the response data can be accessed by GetResponseData().
         * @param url The url string to send to.
         * @param timeout The request timeout in seconds.
         * @return true if successful.
         */
        virtual Bool SendGet(const String& url, Double timeout = 60) = 0;

        /**
         * @brief Send a URL request with http method POST.
         * When posting a URL request the IsPending() state is true.
         * If the URL request was successful the WasFinished() state is true
         * and the response data can be accessed by GetResponseData().\n
         * If the url is redirected, the POST is cancelled and WasRejected() state is true.
         * @param url The url string to send to.
         * @param body The body data to send.
         * @param contentType The string for the "Content-Type" http header field.
         * @param timeout The request timeout in seconds.
         * @return true if successful.
         */
        virtual Bool SendPost(const String& url, const Data& body,
                              const String& contentType, Double timeout = 60) = 0;

        /**
         * @brief Cancel a URL request.
         * This method cancels a URL request if it is pending, and clears its internal state.
         * @return true if successful.
         */
        virtual Bool Cancel() = 0;

        /**
         * @brief Get the custom HTTP headers defined for this request.
         * @return The map of header key/value pairs.
         */
        virtual const Map<String, String>& GetHeaders() const = 0;

        /**
         * @brief Get the URL request string.
         * @return The url which was passed to SendGet() or SendPost().
         */
        virtual const String& GetUrlString() const = 0;

        /**
         * @brief Get the URL request's response status code.
         * The status code is available if WasFinished() returns true.
         * @return The response status code.
         */
        virtual SInt32 GetResponseStatusCode() const = 0;

        /**
         * @brief Get the URL request's response data.
         * The data is available if WasFinished() returns true.
         * @return The URL request response data.
         */
        virtual const Data& GetResponseData() const = 0;

        /**
         * @brief Get the HTTP headers received with this URL request's response.
         * The headers are available if WasFinished() returns true.
         * @return The map of header key/value pairs.
         */
        virtual const Map<String, String>& GetResponseHeaders() const = 0;

        /**
         * @brief Get the current response data size.
         * The size is updated while receiving data asynchronous.
         * @return The current response data byte size.
         */
        virtual UInt64 GetCurrentDataSize() const = 0;

        /**
         * @brief Release the response data.
         * Releasing the data can be performed only if the URL request is not pending.
         * @return true if successful.
         */
        virtual Bool ReleaseData() = 0;

        /**
         * @brief Check if the URL request is idle, i.e. ready to start a GET or POST operation.
         * The request is idle if it is not waiting for a response and not waiting to be cancelled.
         * @return true if idle.
         */
        virtual Bool IsIdle() const = 0;
        /**
         * @brief Check if the URL request is pending, i.e. waiting for a response.
         * @return true if pending.
         */
        virtual Bool IsPending() const = 0;
        /**
         * @brief Check if the URL request waiting to be cancelled.
         * @return true if cancelling.
         */
        virtual Bool IsCancelling() const = 0;

        /**
         * @brief Check if the URL request was finished in the most recent tick.
         * @return true if finished.
         */
        virtual Bool WasFinished() const = 0;
        /**
         * @brief Check if the URL request was rejected in the most recent tick.
         * @return true if rejected.
         */
        virtual Bool WasRejected() const = 0;
        /**
         * @brief Check if the URL request was cancelled in the most recent tick.
         * @return true if cancelled.
         */
        virtual Bool WasCancelled() const = 0;

    protected:
        virtual ~IUrlRequest() {}
    };
}

#endif  // __MURL_I_URL_REQUEST_H__
