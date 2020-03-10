// Copyright 2010-2015 Spraylight

#ifndef __MURL_I_APP_STORE_PRODUCT_H__
#define __MURL_I_APP_STORE_PRODUCT_H__

#include "murl_data.h"
#include "murl_enum.h"

namespace Murl
{
    /**
     * @ingroup MurlControlInterfaces
     * @interface IAppStoreProduct
     * @brief The IAppStoreProduct interface.
     * The IAppStoreProduct object can be created by the IAppStoreControl object.
     */
    class IAppStoreProduct
    {
    public:
        /**
         * @brief Enumeration of the product status.
         * Use GetStatus() to get the current status.
         */
        enum Status
        {
            /** The product is not purchased. */
            STATUS_NOT_PURCHASED,

            /** Purchasing the product is in progress. */
            STATUS_PURCHASE_PENDING,
            /** The product is purchased. */
            STATUS_PURCHASED,
            /** Purchasing the product is cancelled. */
            STATUS_PURCHASE_CANCELLED,

            /** Consuming the product is in progress. */
            STATUS_CONSUME_PENDING,
            /** The product is consumed. */
            STATUS_CONSUMED,
            /** Consuming the product is cancelled. */
            STATUS_CONSUME_CANCELLED,

            /** Purchase error. */
            STATUS_ERROR
        };

        /**
         * @brief Get the product purchase status.
         * The purchase operation works asynchronously, the application
         * can check the current status to operate correctly.
         * @return The product purchase status.
         */
        virtual Status GetStatus() const = 0;

        /**
         * @brief Clear the product purchase status.
         *  Set the product purchase status to IAppStoreProduct::STATUS_NOT_PURCHASED
         *  if the product purchase status is IAppStoreProduct::STATUS_PURCHASE_CANCELLED.\n
         *  Set the product purchase status to IAppStoreProduct::STATUS_PURCHASED
         *  if the product purchase status is IAppStoreProduct::STATUS_CONSUME_CANCELLED.
         * @return true if successful.
         */
        virtual Bool ClearStatus() = 0;

        /**
         * @brief Check if the product is initialized.
         * The product is initialized when connecting to the
         * app-store was successful.
         * @return true if the product is initialized.
         */
        virtual Bool IsInitialized() const = 0;
        /**
         * @brief Check if the product is valid on the app-store.
         * @return true if the product is valid on the app-store.
         */
        virtual Bool IsValid() const = 0;

        /**
         * @brief Get the identifier of the product.
         * @return The identifier of the product.
         */
        virtual const String& GetId() const = 0;

        /**
         * @brief Enumeration of the product types.
         */
        enum ProductType
        {
            /** The product is non-consumable. */
            PRODUCT_TYPE_NON_CONSUMABLE,
            /** The product is consumable. */
            PRODUCT_TYPE_CONSUMABLE,
            /** The product is auto-renewable. */
            PRODUCT_TYPE_AUTO_RENEWABLE
        };
        /**
         * @brief Get the product type.
         * @return The product type.
         */
        virtual ProductType GetProductType() const = 0;

        /**
         * @brief Get the title of the product.
         * @return The product title.
         */
        virtual const String& GetTitle() const = 0;
        /**
         * @brief Get the description of the product.
         * @return The product description.
         */
        virtual const String& GetDescription() const = 0;
        /**
         * @brief Get the price of the product.
         * @return The product price.
         */
        virtual const String& GetPrice() const = 0;
        /**
         * @brief Get the localized price of the product.
         *  The localized price description contains the currency symbol
         *  and the corresponding currency number format.
         * @return The localized product price.
         */
        virtual const String& GetLocalPrice() const = 0;
        /**
         * @brief Get the international currency symbol.
         *  A country typically has a local currency symbol and an international currency symbol.\n
         *  The local symbol is used within the country, while the international currency symbol
         *  is used in international contexts to specify that country’s currency unambiguously.
         * @return The international currency symbol.
         */
        virtual const String& GetCurrencyCode() const = 0;

        /**
         * @brief Get the product receipt data.
         *  The purchase receipt data is valid after a successful purchase only.\n
         *  On iOS the data contains the transactionReceipt from SKPaymentTransaction.
         *  On Google Play the data contains the entire RESPONSE_INAPP_PURCHASE_DATA json string.
         *  On Amazon & Samsung store the data contains the order identifier.
         *  On OSX the data is empty.
         * @return The product receipt data.
         */
        virtual const Data& GetReceiptData() const = 0;
        /**
         * @brief Get the product receipt signature data.
         *  The receipt signature data is valid after a successful purchase only.\n
         *  On Google Play the data contains the RESPONSE_INAPP_SIGNATURE.
         *  On iOS & OSX the data contains the transactionIdentifier from SKPaymentTransaction.
         *  On Amazon & Samsung store the data is empty.
         * @return The product receipt signature data.
         */
        virtual const Data& GetReceiptSignature() const = 0;

        /**
         * @brief Get the description string of the last error.
         *  Use ClearLastError() to reset the error status.
         * @return The description string of the last error.
         */
        virtual const String& GetLastError() const = 0;
        /**
         * @brief Clear the last error status and string.
         *  Set the product purchase status to IAppStoreProduct::STATUS_NOT_PURCHASED
         *  if the product purchase status is IAppStoreProduct::STATUS_ERROR.\n
         *  Clear the last error string.
         * @return true if successful.
         */
        virtual Bool ClearLastError() = 0;

    protected:
        virtual ~IAppStoreProduct() {}
    };

    /**
     * @brief Get the IAppStoreProduct::Status enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IAppStoreProduct::Status>& GetIAppStoreProductStatusEnum();

    /**
     * @brief Get the IAppStoreProduct::ProductType enumeration to string mapping.
     * @return The enumeration to string mapping.
     */
    const Enum<IAppStoreProduct::ProductType>& GetIAppStoreProductTypeEnum();
}

#endif  // __MURL_I_APP_STORE_PRODUCT_H__
