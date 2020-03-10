// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_APP_STORE_CONTROL_H__
#define __MURL_I_APP_STORE_CONTROL_H__

#include "murl_i_controlable.h"
#include "murl_i_app_store_product.h"
#include "murl_enum.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IAppStoreControl
     * @brief The IAppStoreControl interface.
     */
    class IAppStoreControl : public IControlable
    {
    public:
        /**
         * @brief Enumeration of the App Store connection status.
         * Use GetStatus() to get the current status.
         */
        enum Status
        {
            /** The connection is idle. */
            STATUS_IDLE,
            /** Connecting to the App Store is in progress. */
            STATUS_CONNECTING,
            /** The connection to the App Store is established. */
            STATUS_CONNECTED,
            /** Connection error. */
            STATUS_ERROR
        };

        /**
         * @brief Get the App Store connection status.
         * The connection operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The App Store connection status.
         */
        virtual Status GetStatus() const = 0;

        /**
         * @brief Register a product to the App Store control.
         * Products can only be registered before calling ConnectToStore() at least once.
         * @param productId The identifier of the product.
         * @param productType The type of the product.
         * @return true if successful.
         */
        virtual Bool RegisterProduct(const String& productId, IAppStoreProduct::ProductType productType) = 0;

        /**
         * @brief Start connecting to the App Store.
         * When starting the connnection, the App Store status changes to
         * IAppStoreControl::STATUS_CONNECTING immediately.
         * When the App Store is connected the App Store status
         * changes to IAppStoreControl::STATUS_CONNECTED.
         * This method also resets the internal status of all registered products
         * to either STATUS_PURCHASED or STATUS_NOT_PURCHASED.
         * @return always true.
         */
        virtual Bool ConnectToStore() = 0;
        /**
         * @brief Disconnect from the App Store.
         * The App Store status changes to IAppStoreControl::STATUS_IDLE immediately.
         * @return always true.
         */
        virtual Bool DisconnectFromStore() = 0;
        /**
         * @brief Reconnect to the App Store.
         * This method is basically identical to calling DisconnectFromStore() followed
         * by a call to ConnectToStore(), except that the internal status of the registered
         * products is not touched. Can be used in a logic implementation when e.g. the app
         * run state changes to APP_RUN_STATE_RUNNING, to refresh the store connection.
         * @return always true.
         */
        virtual Bool ReconnectToStore() = 0;
        /**
         * @brief Restore any previously completed purchase transactions.
         * To successfully restore any previous transactions, the current status
         * must be IAppStoreControl::STATUS_CONNECTED.
         * @return true if successful.
         */
        virtual Bool RestoreTransactions() = 0;

        /**
         * @brief Get the number of available products.
         * The result is only valid after calling ConnectToStore() at least once.
         * @return The number of available products.
         */
        virtual UInt32 GetNumberOfAvailableProducts() const = 0;
        /**
         * @brief Get a product by index.
         * The result is only valid after calling ConnectToStore() at least once.
         * A valid product index is [0 .. GetNumberOfAvailableProducts() - 1].
         * @param index The zero-based index of the product.
         * @return The product object or null if index is out of range.
         */
        virtual IAppStoreProduct* GetAvailableProduct(UInt32 index) = 0;
        /**
         * @brief Get a product by identifier.
         * The result is only valid after calling ConnectToStore() at least once.
         * @param productId The identifier of the product.
         * @return The product object or null if the identifier is not found.
         */
        virtual IAppStoreProduct* GetAvailableProduct(const String& productId) = 0;

        /**
         * Check if the App Store allows to purchase products at all.
         * The result is only valid after calling ConnectToStore() at least once.
         * @return true if in-app purchasing is possible.
         */
        virtual Bool CanPurchaseProducts() const = 0;
        /**
         * @brief Start purchasing of a product.
         * When starting a purchase, the product status changes to
         * IAppStoreProduct::STATUS_PURCHASE_PENDING immediately.
         * The purchase is finished when the product status is
         * IAppStoreProduct::STATUS_PURCHASED.
         * @param product The product to purchase.
         * @return true if starting the purchase was successful.
         */
        virtual Bool PurchaseProduct(IAppStoreProduct* product) = 0;
        /**
         * @brief Consume an already purchased and consumeable product.
         * A product can be consumed if the product type is
         * IAppStoreProduct::PRODUCT_TYPE_CONSUMABLE and the product status
         * is IAppStoreProduct::STATUS_PURCHASED.
         * When starting a consume, the product status changes to
         * IAppStoreProduct::STATUS_CONSUME_PENDING immediately.\n
         * The consume is finished when the product status is
         * IAppStoreProduct::STATUS_CONSUMED, see ConfirmConsumedProduct()
         * to finalize the consumption.
         * @param product The product to consume.
         * @return true if consuming the product was successful.
         */
        virtual Bool ConsumeProduct(IAppStoreProduct* product) = 0;
        /**
         * @brief Confirm consumption of a consumed product.
         * If a product has the status IAppStoreProduct::STATUS_CONSUMED
         * the consumption of the product must be confirmed.
         * When confirming the consumption, the product status changes to 
         * IAppStoreProduct::STATUS_NOT_PURCHASED immediately and the
         * product's receipt data is emptied.
         * @param product The product to confirm consumption.
         * @return true if confirm consumption of the product was successful.
         */
        virtual Bool ConfirmConsumedProduct(IAppStoreProduct* product) = 0;
        /**
         * @brief Try to cancel an already purchased product.
         * This method can be used in a test (sandbox) environment to try
         * to cancel a previously purchased product. Note: Currently this only
         * works for the Google Play store when using a test account; on all
         * other platforms this method simply returns false.
         * @param product The product to cancel.
         * @return true if cancelling was successful.
         */
        virtual Bool TryCancelProduct(IAppStoreProduct* product) = 0;

        /**
         * @brief Get the description string of the last error.
         *  Use ClearLastError() to reset the error status.
         * @return The description string of the last error.
         */
        virtual const String& GetLastError() const = 0;
        /**
         * @brief Clear the last error status and string.
         *  Set the connection status IAppStoreProduct::STATUS_ERROR to IAppStoreProduct::STATUS_CONNECTED
         *  or IAppStoreProduct::STATUS_IDLE.\n
         *  Clear the last error string.
         * @return true if successful.
         */
        virtual Bool ClearLastError() = 0;

    protected:
        virtual ~IAppStoreControl() {}
    };

    /**
     * @brief Get the IAppStoreControl::Status enumeration to string mapping class.
     * @return The enumeration to string mapping.
     */
    const Enum<IAppStoreControl::Status>& GetIAppStoreControlStatusEnum();
}

#endif  // __MURL_I_APP_STORE_CONTROL_H__
