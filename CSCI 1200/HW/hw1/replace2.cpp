#include    <iostream>
#include    <string>

std::string Replace( std::string String1, std::string String2, std::string String3 )
{
    std::string::size_type  Pos( String1.find( String2 ) );

    while( Pos != std::string::npos )
    {
        String1.replace( Pos, String2.length(), String3 );
        Pos = String1.find( String2, Pos + String3.length() );
    }

    return String1;
}

main()
{
    std::string String( "abc012abc012abc012" );

    String = Replace( String, "012", "defg" );
    String = Replace( String, "a", "*" );

    std::cout << String << std::endl;
}
